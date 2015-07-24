#include "calc_exp.h"
#include "opt.h"
#include "compare.h"
#include "next_token.h"
#include <cstdio>

Datatype *calc_exp(){
    char *tk0 = next_token();
	Datatype *res;
    if (*tk0 == '(')
    {
        char *tk1 = next_token();
        Opt *opt;
        Cons *cons = new Cons(NULL, NULL), *tail = cons;
		Datatype *val;
		if(tk1==NULL){printf("123");throw 0;}
		if (strcmp(tk1, "+") == 0)opt = new Add();
		else if (strcmp(tk1, "-") == 0) opt = new Sub();
		else if (strcmp(tk1, "*") == 0) opt = new Mul();
		else if (strcmp(tk1, "/") == 0) opt = new Div();
		else if (strcmp(tk1, "abs") == 0) opt = new Abs();
		else if (strcmp(tk1, "quotient") == 0) opt = new Quotient();
		else if (strcmp(tk1, "remainder") == 0) opt = new Remainder();
		else if (strcmp(tk1, "modulo") == 0) opt = new Modulo();
		else if (strcmp(tk1, "gcd") == 0) opt = new Gcd();
		else if (strcmp(tk1, "lcm") == 0) opt = new Lcm();
		else if (strcmp(tk1, "expt") == 0) opt = new Expt();
		else if (strcmp(tk1, "sqrt") == 0) opt = new Sqrt();
		else if (strcmp(tk1, "numerator") == 0) opt = new Numerator();
		else if (strcmp(tk1, "denominator") == 0) opt = new Denominator();
		else if (strcmp(tk1, "floor") == 0) opt = new Floor();
		else if (strcmp(tk1, "ceiling") == 0) opt = new Ceiling();
		else if (strcmp(tk1, "truncate") == 0) opt = new Truncate();
		else if (strcmp(tk1, "round") == 0) opt = new Round();
		else if (strcmp(tk1, "inexact->exact") == 0) opt = new Toexact();
		else if (strcmp(tk1, "exact->inexact") == 0) opt = new Toinexact();
		else if (strcmp(tk1, "max") == 0) opt = new Max();
		else if (strcmp(tk1, "min") == 0) opt = new Min();
		else if (strcmp(tk1, "sin") == 0) opt = new Sin();
		else if (strcmp(tk1, "cos") == 0) opt = new Cos();
		else if (strcmp(tk1, "tan") == 0) opt = new Tan();
		else if (strcmp(tk1, "asin") == 0) opt = new Asin();
		else if (strcmp(tk1, "acos") == 0) opt = new Acos();
		else if (strcmp(tk1, "atan") == 0) opt = new Atan();
		else if (strcmp(tk1, "exp") == 0) opt = new Exp();
		else if (strcmp(tk1, "log") == 0) opt = new Log();
		else if (strcmp(tk1, "make-rectangular") == 0) opt = new Make_rectangular();
		else if (strcmp(tk1, "make-polar") == 0) opt = new Make_polar();
		else if (strcmp(tk1, "real-part") == 0) opt = new Realpart();
		else if (strcmp(tk1, "imag-part") == 0) opt = new Imagpart();
		else if (strcmp(tk1, "magnitude") == 0) opt = new Magnitude();
		else if (strcmp(tk1, "angle") == 0) opt = new Angle();
		else if (strcmp(tk1, "<") == 0) opt = new Less();
		else if (strcmp(tk1, "<=") == 0) opt = new Lessequal();
		else if (strcmp(tk1, ">") == 0) opt = new Greater();
		else if (strcmp(tk1, ">=") == 0) opt = new Greaterequal();
		else if (strcmp(tk1, "zero?") == 0) opt = new IsZero();
		else if (strcmp(tk1, "negative?") == 0) opt = new IsNegative();
		else if (strcmp(tk1, "positive?") == 0) opt = new IsPositive();
		else if (strcmp(tk1, "odd?") == 0) opt = new IsOdd();
		else if (strcmp(tk1, "even?") == 0) opt = new IsEven();
		else if (strcmp(tk1, "integer?") == 0) opt = new IsInteger();
		else if (strcmp(tk1, "rational?") == 0) opt = new IsRational();
		else if (strcmp(tk1, "real?") == 0) opt = new IsReal();
		else if (strcmp(tk1, "complex?") == 0) opt = new IsComplex();
		else if (strcmp(tk1, "number?") == 0) opt = new IsNumber();
		else if (strcmp(tk1, "exact?") == 0) opt = new IsExact();
		else if (strcmp(tk1, "inexact?") == 0) opt = new IsInexact();

		else throw 0;
        while ((val = calc_exp()))
        {
            tail->cdr = new Cons(val, NULL);
            tail = tail->cdr;
        }
        res = opt->calc(cons->cdr);
        for (Cons *np; cons; cons = np)
        {
            np = cons->cdr;
            delete cons;
        }
    }
    else if (*tk0 == ')')
	{
        return NULL;
	}
    else
    {
		res=Rational::from_string(tk0);
		if(!res) {res = Float::from_string(tk0);}
		if(!res) { res = Complex::from_string(tk0);}
		if (!res) { res = Boolean::from_string(tk0); }
		if(res==NULL){throw 0;}
    }
    return res;
}
