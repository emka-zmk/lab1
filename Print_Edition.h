#pragma once 
#ifndef _PRINT_EDITION_H_ 
#define _PRINT_EDITION_H_ 
#include <iostream> 
class Print_Edition {
public:
	Print_Edition() {}
	virtual ~Print_Edition() {};
	virtual void Print()              const = 0;
	virtual void Save(std::ostream&)  const = 0;
	virtual void Load(std::istream&) = 0;
	virtual bool Menu() = 0;
protected:
};
#endif