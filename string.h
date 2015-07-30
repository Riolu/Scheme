#pragma once
#include "datatype.h"
#include "number.h"
#include "boolean.h"
#include "character.h"
#include <string>
using namespace std;
#define SCAST_STRING(x) static_cast<String*>(x)

class String :public Datatype{
public:
	String(string str="");
	~String();
	virtual Boolean *strIsEqual(String *string2);
	virtual Boolean *strIsCiEqual(String *string2);
	virtual Boolean *strLess(String *string2);
	virtual Boolean *strCiLess(String *string2);
	virtual Boolean *strLessequal(String *string2);
	virtual Boolean *strCiLessequal(String *string2);

	virtual Datatype *strLen();
	virtual Character *strRef(Number *number);

	virtual Datatype *strToNum();
	//virtual Datatype *strToNum(Number *number);

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