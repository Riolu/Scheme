#pragma once
#include "number.h"
#include "long_int.h"
#include "character.h"
#include "string.h"
#include <cstring>
#include <string> 

#define SCAST_RATIONAL(x) static_cast<Rational*>(x)

class Rational : public Number {
public:
	Rational(string numerator = "0", string denominator = "1");
	virtual ~Rational();

	void reduce();
	virtual Number *convert(Number *number2);
	virtual Number *add(Number *number2);
	virtual Number *sub(Number *number2);
	virtual Number *mul(Number *number2);
	virtual Number *div(Number *number2);
	virtual Number *abs();
	virtual Number *quo(Number *number2);
	virtual Number *rem(Number *number2);
	virtual Number *mod(Number *number2);
	virtual Number *gcd(Number *number2);
	virtual Number *lcm(Number *number2);
	virtual Number *expt(Number *number2);
	virtual Number *sqt();
	virtual Number *num();
	virtual Number *den();
	virtual Number *flo();
	virtual Number *cei();
	virtual Number *tru();
	virtual Number *rou();
	virtual Number *toexact();
	virtual Number *toinexact();
	virtual Number *maxi(Number *number2);
	virtual Number *mini(Number *number2);
	virtual Number *sinx();
	virtual Number *cosx();
	virtual Number *tanx();
	virtual Number *asinx();
	virtual Number *acosx();
	virtual Number *atanx();
	virtual Number *atanxy(Number *number2);
	virtual Number *expx();
	virtual Number *logx();
	virtual Number *makerectangular(Number *number2);
	virtual Number *makepolar(Number *number2);
	virtual Number *realpart();
	virtual Number *imagpart();
	virtual Number *mag();
	virtual Number *ang();
	virtual Boolean *less(Number *number2);
	virtual Boolean *lessequal(Number *number2);
	virtual Boolean *greater(Number *number2);
	virtual Boolean *greaterequal(Number *number2);
	virtual Boolean *isZero();
	virtual Boolean *isNegative();
	virtual Boolean *isPositive();
	virtual Boolean *isOdd();
	virtual Boolean *isEven();
	virtual Boolean *isInteger();
	virtual Boolean *isRational();
	virtual Boolean *isReal();
	virtual Boolean *isComplex();
	virtual Boolean *isNumber();
	virtual Boolean *isChar();
	virtual Boolean *isString();
	virtual Boolean *isExact();
	virtual Boolean *isInexact();
	virtual Character *intToChar();
	virtual String *numToStr();
	virtual int returnInt();
	virtual void print();
	static Rational *from_string(const char *expression_in_char);

	LongInt numerator_;
	LongInt denominator_;
};
