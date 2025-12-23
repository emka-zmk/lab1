#ifndef _NOVELISTS_H_ 
#define _NOVELISTS_H_ 

#include <string> 
#include "Print_Edition.h" 

class novelists : public Print_Edition {
public:
    novelists();
    novelists(const novelists&);
    novelists(const std::string& sName);
    ~novelists();

    void        Print()                 const  override;
    void        Save(std::ostream&)     const  override;
    void        Load(std::istream&)            override;
    bool        Menu()                         override;

    void        SetBIO(const std::string& sBIO);
    void        SetYears(const std::string& sYears);
    void        SetBooks(const std::string& sBooks);
    void        SetName(const std::string& sName);

    std::string GetBIO()    const;
    std::string GetYears()       const;
    std::string GetBooks()         const;
    std::string GetName()           const;


private:
    std::string m_sName = "Unknown";
    std::string m_sYears = "1900-1982";
    std::string m_sBooks = "First,Second";
    std::string m_sBIO = "Died_Alone";
};

#endif