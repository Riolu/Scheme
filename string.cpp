#include "string.h"
#include <cstring>
#include <iostream>

String::String(string str) :string_(str){
	type_ = STRING;
}

String::~String(){}

Boolean *String::strIsEqual(String *string2){
	return new Boolean(string_ == string2->string_);
}

Boolean *String::strIsCiEqual(String *string2){
	string str1 = "", str2 = "";
	for (int i = 0; i < string_.size(); ++i){
		if (string_[i] >= 'a' && string_[i] <= 'z') str1 += string_[i] - 32;
		else str1 += string_[i];
	}
	for (int i = 0; i < string2->string_.size(); ++i){
		if (string2->string_[i] >= 'a' && string2->string_[i] <= 'z') str2 += string2->string_[i] - 32;
		else str2 += string2->string_[i];
	}
	return new Boolean(str1 == str2);
}

Boolean *String::strLess(String *string2){
	return new Boolean(string_ < string2->string_);
}

Boolean *String::strCiLess(String *string2){
	string str1 = "", str2 = "";
	for (int i = 0; i < string_.size(); ++i){
		if (string_[i] >= 'a' && string_[i] <= 'z') str1 += string_[i] - 32;
		else str1 += string_[i];
	}
	for (int i = 0; i < string2->string_.size(); ++i){
		if (string2->string_[i] >= 'a' && string2->string_[i] <= 'z') str2 += string2->string_[i] - 32;
		else str2 += string2->string_[i];
	}
	return new Boolean(str1 < str2);
}

Boolean *String::strLessequal(String *string2){
	return new Boolean(string_ <= string2->string_);
}

Boolean *String::strCiLessequal(String *string2){
	string str1 = "", str2 = "";
	for (int i = 0; i < string_.size(); ++i){
		if (string_[i] >= 'a' && string_[i] <= 'z') str1 += string_[i] - 32;
		else str1 += string_[i];
	}
	for (int i = 0; i < string2->string_.size(); ++i){
		if (string2->string_[i] >= 'a' && string2->string_[i] <= 'z') str2 += string2->string_[i] - 32;
		else str2 += string2->string_[i];
	}
	return new Boolean(str1 <= str2);
}


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
