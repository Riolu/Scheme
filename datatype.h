#pragma once

class Datatype{
public:
	enum{
		RATIONAL = 1,
		FLOAT = 2,
		COMPLEX = 3,
		BOOLEAN = 4
	} type_;
	Datatype(){}
	virtual ~Datatype(){};
	virtual void print() = 0;
};

