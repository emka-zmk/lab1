#pragma once 
#ifndef _KEEPER_H_ 
#define _KEEPER_H_ 

#include <string> 
#include <exception> 
#include "Print_Edition.h" 

class Keeper {
public:
    Keeper();
    Keeper(int nCopacity);
    Keeper(const Keeper&);
    ~Keeper();

    bool        Save();
    void        Load();
    bool        AddSaveFile(const std::string& sPath);
    void        Print() const;
    void        PushBack(Print_Edition* pObj);
    void        operator+=(Print_Edition* pObj);
    Print_Edition& operator[](int nIndex);
    int         GetSize() const;

private:
    std::string m_sSaveFilePath;
    Print_Edition** m_pObjectBuff;
    int         m_nSize = 0;
    int         m_nCopacity = 0;

    void        ReallocBuff(int nNewCopacity);
};

#endif