#include "novelists.h" 

novelists::novelists() {
}

novelists::novelists(const novelists& novelists) {
    m_sName = novelists.m_sName;
    m_sYears = novelists.m_sYears;
    m_sBooks = novelists.m_sBooks;
    m_sBIO = novelists.m_sBIO;
}
novelists::novelists(const std::string& sName) {
    m_sName = sName;
}
novelists::~novelists() {
}
void novelists::Print() const {
    std::cout << "Novelist:\n";
    std::cout << m_sName << ", ";
    std::cout << m_sYears << ", " << std::endl;
    std::cout << m_sBooks << ", " << std::endl;
    std::cout << m_sBIO << ", " << std::endl;
}
void novelists::SetBIO(const std::string& sBIO) {
    m_sBIO = sBIO;
}
void novelists::SetYears(const std::string& sYears) {
    m_sYears = sYears;
}
void novelists::SetBooks(const std::string& sBooks) {
    m_sBooks = sBooks;
}
void novelists::SetName(const std::string& sName) {
    m_sName = sName;
}
std::string novelists::GetBIO() const {
    return m_sBIO;
}
std::string novelists::GetYears() const {
    return m_sYears;
}
std::string novelists::GetBooks() const {
    return m_sBooks;
}
std::string novelists::GetName() const {
    return m_sName;
}
void novelists::Save(std::ostream& os) const {
    os << "Novelist:\n";
    os << "Name: " << m_sName << "\n";
    os << "Years: " << m_sYears << "\n";
    os << "Books: " << m_sBooks << "\n";
    os << "BIO: " << m_sBIO << "\n";
    os << "end\n\n";
    std::cout << "Novelist saved successfully.\n";
}
void novelists::Load(std::istream& is) {
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
    }
    std::cout << "Novelist loaded successfully.\n";
}

bool novelists::Menu() {
    int choice;
    while (1) {
        std::cout << "1. Print novelist information\n";
        std::cout << "2. Set novelist name\n";
        std::cout << "3. Set novelist years of life\n";
        std::cout << "4. Set novelist books\n";
        std::cout << "5. Set novelist BIO\n";
        std::cout << "6. Exit\n";
        std::cin >> choice;
        switch (choice) {
        case 1:
            this->Print();
            break;
        case 2:
        {
            std::string name;
            std::cout << "Enter novelist name: ";
            std::cin >> name;
            this->SetName(name);
        }
        break;
        case 3:
        {
            std::string Years;
            std::cout << "Enter novelist years: ";
            std::cin >> Years;
            this->SetYears(Years);
        }
        break;
        case 4:
        {
            std::string Books;
            std::cout << "Enter novelist books: ";
            std::cin >> Books;
            this->SetBooks(Books);
        }
        break;
        case 5:


        {
            std::string BIO;
            std::cout << "Enter novelist BIO: ";
            std::cin >> BIO;
            this->SetBIO(BIO);
        }
        break;
        case 6:
            return true;
            break;
        default:
            std::cout << "Invalid choice.\n";
            return true;
            break;
        }
    }
}