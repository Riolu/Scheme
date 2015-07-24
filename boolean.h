#pragma once
#include "datatype.h"

class Boolean :public Datatype{
public:
	Boolean(bool value = false);
	~Boolean();
	virtual Boolean *isInteger();
	virtual Boolean *isRational();
	virtual Boolean *isReal();
	virtual Boolean *isComplex();
	virtual Boolean *isNumber();
	virtual void print();
	static Boolean *from_string(const char*expression);
	
	bool value_;
};