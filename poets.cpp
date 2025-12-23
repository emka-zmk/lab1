#include "poets.h" 
poets::poets() {
}
poets::poets(const poets& poets) {
    m_sName = poets.m_sName;
    m_sYears = poets.m_sYears;
    m_sBooks = poets.m_sBooks;
}
poets::poets(const std::string& sName) {
    m_sName = sName;
}
poets::~poets() {
}
void poets::Print() const {
    std::cout << "Novelist:\n";
    std::cout << m_sName << ", ";
    std::cout << m_sYears << ", " << std::endl;
    std::cout << m_sBooks << ", " << std::endl;
}
void poets::SetYears(const std::string& sYears) {
    m_sYears = sYears;
}
void poets::SetBooks(const std::string& sBooks) {
    m_sBooks = sBooks;
}
void poets::SetName(const std::string& sName) {
    m_sName = sName;
}
std::string poets::GetYears() const {
    return m_sYears;
}
std::string poets::GetBooks() const {
    return m_sBooks;
}
std::string poets::GetName() const {
    return m_sName;
}
void poets::Save(std::ostream& os) const {
    os << "Poet:\n";
    os << "Name: " << m_sName << "\n";
    os << "Years: " << m_sYears << "\n";
    os << "Books: " << m_sBooks << "\n";
    os << "end\n\n";
    std::cout << "Poet saved successfully.\n";
}



void poets::Load(std::istream& is) {
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
    }
    std::cout << "Poet loaded successfully.\n";
}
bool poets::Menu() {
    int choice;
    while (1) {
        std::cout << "1. Print poet information\n";
        std::cout << "2. Set poet name\n";
        std::cout << "3. Set poet years of life\n";
        std::cout << "4. Set poet books\n";
        std::cout << "5. Exit\n";
        std::cin >> choice;
        switch (choice) {
        case 1:
            this->Print();
            break;
        case 2:
        {
            std::string name;
            std::cout << "Enter poet name: ";
            std::cin >> name;
            this->SetName(name);
        }
        break;
        case 3:
        {
            std::string Years;
            std::cout << "Enter poet years: ";
            std::cin >> Years;
            this->SetYears(Years);
        }
        break;
        case 4:
        {
            std::string Books;
            std::cout << "Enter poet books: ";
            std::cin >> Books;
            this->SetBooks(Books);
        }
        break;
        case 5:
            return true;
            break;


        default:
            std::cout << "Invalid choice.\n";
            return true;
            break;
        }
    }
}