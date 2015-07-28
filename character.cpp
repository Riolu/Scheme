#include "character.h"
#include "rational.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

char upper(char ch){
	if (ch >= 'a' && ch <= 'z') return (char)(ch - 32);
	else if (ch >= 'A' && ch <= 'Z') return ch;
	else return ch;
}

char lower(char ch){
	if (ch >= 'a' && ch <= 'z') return ch;
	else if (ch >= 'A' && ch <= 'Z') return (char)(ch + 32);
	else return ch;
}

void turn(string &str, int n){
	if (n / 10 == 0) str += n + '0';
	else{
		turn(str, n / 10);
		str += n % 10 + '0';
	}
}

Character::Character(char ch) :char_(ch){
	type_ = CHARACTER;
}

Character::~Character(){}

Boolean *Character::charIsEqual(Character *char2){
	return new Boolean(char_ == char2->char_);
}

Boolean *Character::charIsCiEqual(Character *char2){
	if (((char_ >= 'a'&&char_ <= 'z') || (char_ >= 'A'&&char_ <= 'Z')) && ((char2->char_ >= 'a'&&char2->char_ <= 'z') || (char2->char_ >= 'A'&&char2->char_ <= 'Z'))){
		if (char_ == char2->char_ || abs(char_ - char2->char_) == 32) return new Boolean(true);
		else return new Boolean(false);
	}
	else return new Boolean(char_ == char2->char_);
}

Boolean *Character::charLess(Character *char2){
	return new Boolean(char_ < char2->char_);
}

Boolean *Character::charCiLess(Character *char2){
	if (((char_ >= 'a'&&char_ <= 'z') || (char_ >= 'A'&&char_ <= 'Z')) && ((char2->char_ >= 'a'&&char2->char_ <= 'z') || (char2->char_ >= 'A'&&char2->char_ <= 'Z'))){
		if (upper(char_) < upper(char2->char_)) return new Boolean(true);
		else return new Boolean(false);
	}
	else return new Boolean(char_ < char2->char_);
}

Boolean *Character::charLessequal(Character *char2){
	return new Boolean(char_ <= char2->char_);
}

Boolean *Character::charCiLessequal(Character *char2){
	if (((char_ >= 'a'&&char_ <= 'z') || (char_ >= 'A'&&char_ <= 'Z')) && ((char2->char_ >= 'a'&&char2->char_ <= 'z') || (char2->char_ >= 'A'&&char2->char_ <= 'Z'))){
		if (upper(char_) <= upper(char2->char_)) return new Boolean(true);
		else return new Boolean(false);
	}
	else return new Boolean(char_ <= char2->char_);
}

Boolean *Character::charIsAlpha(){
	return new Boolean((char_ >= 'a' && char_ <= 'z') || (char_ >= 'A' && char_ <= 'Z'));
}

Boolean *Character::charIsNum(){
	return new Boolean(char_ >= '0' && char_ <= '9');
}

Boolean *Character::charIsUpCase(){
	return new Boolean(char_ >= 'A' && char_ <= 'Z');
}

Boolean *Character::charIsLowCase(){
	return new Boolean(char_ >= 'a' && char_ <= 'z');
}

Datatype *Character::charToInt(){
	string tmp = "";
	turn(tmp, int(char_));
	return new Rational(tmp, "1");
}

Character *Character::charToUpCase(){
	if (char_ >= 'a' && char_ <= 'z') return new Character(char_ - 32);
	else return new Character(char_);
}

Character *Character::charToDownCase(){
	if (char_ >= 'A' && char_ <= 'Z') return new Character(char_ + 32);
	else return new Character(char_);
}



Boolean *Character::isInteger(){
	return new Boolean(false);
}

Boolean *Character::isRational(){
	return new Boolean(false);
}

Boolean *Character::isReal(){
	return new Boolean(false);
}

Boolean *Character::isComplex(){
	return new Boolean(false);
}

Boolean *Character::isNumber(){
	return new Boolean(false);
}

Boolean *Character::isChar(){
	return new Boolean(true);
}

Boolean *Character::isString(){
	return new Boolean(false);
}

void Character::print(){
	printf("#\\%c", char_);
}

Character *Character::from_string(const char *expression){
	if (strlen(expression) != 3) return NULL; 
	if (!(expression[0] == '#' && expression[1] == '\\')) return NULL;
	return new Character(expression[2]);
}