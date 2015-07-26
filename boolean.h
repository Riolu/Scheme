#pragma once
#include "datatype.h"
#define SCAST_BOOLEAN(x) static_cast<Boolean*>(x)

class Boolean :public Datatype{
public:
	Boolean(bool value = false);
	~Boolean();
	virtual Boolean *isInteger();
	virtual Boolean *isRational();
	virtual Boolean *isReal();
	virtual Boolean *isComplex();
	virtual Boolean *isNumber();
	virtual Boolean *isChar();
	virtual void print();
	static Boolean *from_string(const char*expression);
	
	bool value_;
};