#pragma once
#include "datatype.h"
#include "boolean.h"
#include <string>
using namespace std;
#define SCAST_STRING(x) static_cast<String*>(x)

class String :public Datatype{
public:
	String(string str="");
	~String();
	virtual Boolean *isInteger();
	virtual Boolean *isRational();
	virtual Boolean *isReal();
	virtual Boolean *isComplex();
	virtual Boolean *isNumber();
	virtual Boolean *isChar();
	virtual Boolean *isString();
	virtual void print();
	static String *from_string(const char*expression);
	
	string string_;
};