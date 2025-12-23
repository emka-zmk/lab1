#include "fantasists.h" 
fantasists::fantasists() {
}
fantasists::fantasists(const fantasists& fantasists) {
    m_sName = fantasists.m_sName;
    m_sYears = fantasists.m_sYears;
    m_sBooks = fantasists.m_sBooks;
    m_sBIO = fantasists.m_sBIO;
    m_sFilm_Adapt = fantasists.m_sFilm_Adapt;
}
fantasists::fantasists(const std::string& sName) {
    m_sName = sName;
}
fantasists::~fantasists() {
}
void fantasists::Print() const {
    std::cout << "Novelist:\n";
    std::cout << m_sName << ", ";
    std::cout << m_sYears << ", " << std::endl;
    std::cout << m_sBooks << ", " << std::endl;
    std::cout << m_sBIO << ", " << std::endl;
    std::cout << m_sFilm_Adapt << ", " << std::endl;
}
void fantasists::SetFilm_Adapt(const std::string& sFilm_Adapt) {
    m_sFilm_Adapt = sFilm_Adapt;
}
void fantasists::SetBIO(const std::string& sBIO) {
    m_sBIO = sBIO;
}
void fantasists::SetYears(const std::string& sYears) {
    m_sYears = sYears;
}
void fantasists::SetBooks(const std::string& sBooks) {
    m_sBooks = sBooks;
}
void fantasists::SetName(const std::string& sName) {
    m_sName = sName;
}
std::string fantasists::GetFilm_Adapt() const {
    return m_sFilm_Adapt;
}
std::string fantasists::GetBIO() const {
    return m_sBIO;
}
std::string fantasists::GetYears() const {
    return m_sYears;
}

std::string fantasists::GetBooks() const {
    return m_sBooks;
}

std::string fantasists::GetName() const {
    return m_sName;
}

void fantasists::Save(std::ostream& os) const {
    os << "Fantasist:\n";
    os << "Name: " << m_sName << "\n";
    os << "Years: " << m_sYears << "\n";
    os << "Books: " << m_sBooks << "\n";
    os << "BIO: " << m_sBIO << "\n";
    os << "Film Adaptation: " << m_sFilm_Adapt << "\n";
    os << "end\n\n";
    std::cout << "Fantasist saved successfully.\n";
}

void fantasists::Load(std::istream& is) {
    while (!is.eof()) {
        std::string key, value;
        is >> key;
        if (key == "end")
            break;
        is >> value;
        if (key == "Name:") {
            m_sName = value;
        }
        else if (key == "Years:") {
            m_sYears = value;
        }
        else if (key == "Books:") {
            m_sBooks = value;
        }
        else if (key == "BIO:") {
            m_sBIO = value;
        }
        else if (key == "Film_Adapt:") {
            m_sFilm_Adapt = value;
        }
    }
    std::cout << "Fantasist loaded successfully.\n";
}

bool fantasists::Menu() {
    int choice;
    while (1) {
        std::cout << "1. Print fantasist information\n";
        std::cout << "2. Set fantasist name\n";
        std::cout << "3. Set fantasist years of life\n";
        std::cout << "4. Set fantasist books\n";
        std::cout << "5. Set fantasist BIO\n";
        std::cout << "6. Set fantasist Film Adaptations\n";
        std::cout << "7. Exit\n";


        std::cin >> choice;
        switch (choice) {
        case 1:
            this->Print();
            break;
        case 2:
        {
            std::string name;
            std::cout << "Enter fantasist name: ";
            std::cin >> name;
            this->SetName(name);
        }
        break;
        case 3:
        {
            std::string Years;
            std::cout << "Enter fantasist years: ";
            std::cin >> Years;
            this->SetYears(Years);
        }
        break;
        case 4:
        {
            std::string Books;
            std::cout << "Enter fantasist books: ";
            std::cin >> Books;
            this->SetBooks(Books);
        }
        break;
        case 5:
        {
            std::string BIO;
            std::cout << "Enter fantasist BIO: ";
            std::cin >> BIO;
            this->SetBIO(BIO);
        }
        case 6:
        {
            std::string Film_Adapt;
            std::cout << "Enter fantasist Film Adaptation: ";
            std::cin >> Film_Adapt;
            this->SetFilm_Adapt(Film_Adapt);
        }
        break;
        case 7:
            return true;
            break;
        default:
            std::cout << "Invalid choice.\n";
            return true;
            break;
        }
    }
}