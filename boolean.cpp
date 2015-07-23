#include "boolean.h"
#include <cstdio>
#include <cstring>

Boolean::Boolean(bool value) :value_(value){
	type_ = BOOLEAN;
}

Boolean::~Boolean(){}

void Boolean::print(){
	if (value_) printf("#t");
	else printf("#f");
}

Boolean *Boolean::from_string(const char *expression){
	if (strcmp(expression, "#t") == 0 || strcmp(expression, "#T") == 0) return new Boolean(true);
	if (strcmp(expression, "#f") == 0 || strcmp(expression, "#F") == 0) return new Boolean(false);
	else return NULL;
}
