#pragma once 
#ifndef _FANTASISTS_H_ 
#define _FANTASISTS_H_ 

#include <string> 
#include "Print_Edition.h" 

class fantasists : public Print_Edition {
public:
    fantasists();
    fantasists(const fantasists&);
    fantasists(const std::string& sName);
    ~fantasists();

    void        Print()                 const  override;
    void        Save(std::ostream&)     const  override;
    void        Load(std::istream&)            override;
    bool        Menu()                         override;

    void        SetFilm_Adapt(const std::string& sFilm_Adapt);
    void        SetBIO(const std::string& sBIO);
    void        SetYears(const std::string& sYears);
    void        SetBooks(const std::string& sBooks);
    void        SetName(const std::string& sName);

    std::string GetFilm_Adapt()    const;
    std::string GetBIO()    const;
    std::string GetYears()       const;
    std::string GetBooks()         const;
    std::string GetName()           const;

private:
    std::string m_sName = "Unknown";
    std::string m_sYears = "2012-2024";
    std::string m_sBooks = "Sixth,Seventh";
    std::string m_sBIO = "Died_young";
    std::string m_sFilm_Adapt = "Sixth_book_has_adaptation";

};

#endif