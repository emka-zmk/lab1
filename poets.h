#pragma once 
#ifndef _POETS_H_ 
#define _POETS_H_ 

#include <string> 
#include "Print_Edition.h" 

class poets : public Print_Edition {
public:
    poets();
    poets(const poets&);
    poets(const std::string& sName);
    ~poets();

    void        Print()                 const  override;
    void        Save(std::ostream&)     const  override;
    void        Load(std::istream&)            override;
    bool        Menu()                         override;

    void        SetYears(const std::string& sYears);
    void        SetBooks(const std::string& sBooks);
    void        SetName(const std::string& sName);

    std::string GetYears()       const;
    std::string GetBooks()         const;
    std::string GetName()           const;

private:
    std::string m_sName = "Unknown";
    std::string m_sYears = "1621-1642";
    std::string m_sBooks = "Third_Fourth_Fifth";
};

#endif