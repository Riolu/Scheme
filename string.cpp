#include "string.h"
#include <cstring>
#include <iostream>

String::String(string str) :string_(str){
	type_ = STRING;
}

String::~String(){}



Boolean *String::isInteger(){
	return new Boolean(false);
}

Boolean *String::isRational(){
	return new Boolean(false);
}

Boolean *String::isReal(){
	return new Boolean(false);
}

Boolean *String::isComplex(){
	return new Boolean(false);
}

Boolean *String::isNumber(){
	return new Boolean(false);
}

Boolean *String::isChar(){
	return new Boolean(false);
}

Boolean *String::isString(){
	return new Boolean(true);
}

void String::print(){
	cout << "\"" << string_ << "\"";
}

String *String::from_string(const char *expression){
	int len = strlen(expression);
	if (expression[0] != '\"' || expression[len - 1] != '\"') return NULL;
	string str = expression;
	return new String(str.substr(1,len-2));
}
