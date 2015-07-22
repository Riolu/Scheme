#pragma once

#define SCAST_NUMBER(x) static_cast<Number*>(x)

class Number {
public:
	enum{
		RATIONAL = 1,
		FLOAT = 2,
		COMPLEX = 3
	} type_;
	Number(){}
	virtual ~Number(){}
	virtual Number *convert(Number *number2) = 0;
	virtual Number *add(Number *number2) = 0;
	virtual Number *sub(Number *number2) = 0;
	virtual Number *mul(Number *number2) = 0;
	virtual Number *div(Number *number2) = 0;
	virtual Number *abs() = 0;
	virtual Number *quo(Number *number2) = 0;
	virtual Number *rem(Number *number2) = 0;
	virtual Number *mod(Number *number2) = 0;
	virtual Number *gcd(Number *number2) = 0;
	virtual Number *lcm(Number *number2) = 0;
	virtual Number *expt(Number *number2) = 0;
	virtual Number *sqt() = 0;
	virtual Number *num() = 0;
	virtual Number *den() = 0;
	virtual Number *flo() = 0;
	virtual Number *cei() = 0;
	virtual Number *tru() = 0;
	virtual Number *rou() = 0;
	virtual Number *toexact() = 0;
	virtual Number *toinexact() = 0;
	virtual Number *maxi(Number *number2) = 0;
	virtual Number *mini(Number *number2) = 0;
	virtual Number *sinx() = 0;
	virtual Number *cosx() = 0;
	virtual Number *tanx() = 0;
	virtual Number *asinx() = 0;
	virtual Number *acosx() = 0;
	virtual Number *atanx() = 0;
	virtual Number *expx() = 0;
	virtual Number *logx() = 0;
	virtual Number *makerectangular(Number *number2) = 0;
	virtual Number *makepolar(Number *number2) = 0;
	virtual Number *mag() = 0;
	virtual Number *ang() = 0;
	virtual Number *realpart() = 0;
	virtual Number *imagpart() = 0;
	virtual void print() = 0;
};
