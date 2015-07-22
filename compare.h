#include "opt.h"
#include "float.h"
#include "rational.h"
#include "complex.h"
#include "number.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <complex>
#include <cstdlib>
#define SCAST_RATIONAL(x) static_cast<Rational*>(x)
#define SCAST_FLOAT(x) static_cast<Float*>(x)

class Add : public Opt {
    /* Use the lowest level type */
    Number *calc(Cons *con) {
		
		Number *res = new Rational("0","1");
		Number *last;	
        for (; con; con = con->cdr)
        {
			if(con->car->type_>3||con->car->type_<1)
			{
				throw 0;
			}
            Number *opr = con->car, *conv;
            last = res;
            if (res->type_ > opr->type_)
			{
				res = res->add(conv = res->convert(opr));
			}
            else
			{
                res = (conv = opr->convert(res))->add(opr);
			}
			
            delete last;
            delete conv;
			
        }
        return res;
    }
};

class Sub:public Opt{
	Number *calc(Cons *con)
	{
		Cons *tmp=con;
		int cnt=0;
		for(;tmp;tmp=tmp->cdr)
		{
			if(tmp->car->type_>3||tmp->car->type_<1)
			{
				throw 0;
			}
			cnt++;
		}
		Number *res=new Rational("0", "1"),*last;
		Number *opr = con->car, *conv;
		last=res;
		if(cnt==1)
		{
			if (res->type_ > opr->type_)
				res = res->sub(conv = res->convert(opr));
			else
				res = (conv = opr->convert(res))->sub(opr);
			delete last;
			delete conv;
			return res;
		}
		if (res->type_ > opr->type_)
            res = res->add(conv = res->convert(opr));
        else
            res = (conv = opr->convert(res))->add(opr);
        con=con->cdr;
        delete last;
        delete conv;
		for(;con;con=con->cdr)
		{
			opr=con->car;
			last=res;
			if(res->type_>opr->type_)
				res=res->sub(conv=res->convert(opr));
			else
				res=(conv=opr->convert(res))->sub(opr);
			delete last;
			delete conv;
		}
		return res;
	}
};

class Mul : public Opt {
    /* Use the lowest level type */
    Number *calc(Cons *con) {
		Number *res = new Rational("1", "1"), *last;
        for (; con; con = con->cdr)
        {
			if(con->car->type_>3||con->car->type_<1)
			{
				throw 0;
			}
            Number *opr = con->car, *conv;
            last = res;
            if (res->type_ > opr->type_)
                res = res->mul(conv = res->convert(opr));
            else
                res = (conv = opr->convert(res))->mul(opr);
            delete last;
            delete conv;
        }
        return res;
    }
};

class Div:public Opt{
	Number *calc(Cons *con)
	{
		Cons *tmp=con;
		int cnt=0;
		for(;tmp;tmp=tmp->cdr)
		{
			if(tmp->car->type_>3||tmp->car->type_<1)
			{
				throw 0;
			}
			cnt++;
		}
		Number *res=new Rational("1","1"),*last;
		Number *opr=con->car,*conv;
		last=res;
		Number *zero = new Float(0.0);
		if(cnt==1)
		{
			if(res->type_>opr->type_)
				res=res->div(conv=res->convert(opr));
			else
				res=(conv=opr->convert(res))->div(opr);
			delete last;
			delete conv;
			return res;
		}
		if(res->type_>opr->type_)
			res=res->mul(conv=res->convert(opr));
		else
			res=(conv=opr->convert(res))->mul(opr);
		con=con->cdr;
		delete last;
		delete conv;
		for(;con;con=con->cdr)
		{
			opr=con->car;
			last=res;
			if(res->type_>opr->type_)
				res=res->div(conv=res->convert(opr));
			else
				res=(conv=opr->convert(res))->div(opr);
			delete last;
			delete conv;
		}
		return res;
	}
};

class Abs:public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->abs();
	}
};

class Quotient:public Opt{
	Number *calc(Cons *con){
		assert(con->cdr->cdr == NULL && "expected number of arguments is 2");
		Number *res = con->car, *opr = con->cdr->car, *last, *conv;
		if (res->type_<1 || res->type_>3) throw 0;
		if (opr->type_<1 || opr->type_>3) throw 0;
		last = res;
		if (res->type_ > opr->type_)
			res = res->quo(conv = res->convert(opr));
		else
			res = (conv = opr->convert(res))->quo(opr);
		delete last;
		delete conv;
		return res;
	}
};

class Remainder:public Opt{
	Number *calc(Cons *con){
		assert(con->cdr->cdr == NULL && "expected number of arguments is 2");
		Number *res = con->car, *opr = con->cdr->car, *last, *conv;
		if (res->type_<1 || res->type_>3) throw 0;
		if (opr->type_<1 || opr->type_>3) throw 0;
		last = res;
		if (res->type_ > opr->type_)
			res = res->rem(conv = res->convert(opr));
		else
			res = (conv = opr->convert(res))->rem(opr);
		delete last;
		delete conv;
		return res;
	}
};

class Modulo :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr->cdr == NULL && "expected number of arguments is 2");
		Number *res = con->car, *opr = con->cdr->car, *last, *conv;
		if (res->type_<1 || res->type_>3) throw 0;
		if (opr->type_<1 || opr->type_>3) throw 0;
		last = res;
		if (res->type_ > opr->type_)
			res = res->mod(conv = res->convert(opr));
		else
			res = (conv = opr->convert(res))->mod(opr);
		delete last;
		delete conv;
		return res;
	}
};

class Gcd :public Opt{
	Number *calc(Cons *con) {
		Number *res = new Rational("0", "1");
		Number *last;
		for (; con; con = con->cdr){
			if (con->car->type_>3 || con->car->type_<1) throw 0;
			Number *opr = con->car, *conv;
			last = res;
			if (res->type_ > opr->type_) res = res->gcd(conv = res->convert(opr));
			else res = (conv = opr->convert(res))->gcd(opr);
			delete last;
			delete conv;
		}
		return res;
	}
};

class Lcm :public Opt{
	Number *calc(Cons *con) {
		Number *res = new Rational("1", "1");
		Number *last;
		for (; con; con = con->cdr){
			if (con->car->type_>3 || con->car->type_<1) throw 0;
			Number *opr = con->car, *conv;
			last = res;
			if (res->type_ > opr->type_) res = res->lcm(conv = res->convert(opr));
			else res = (conv = opr->convert(res))->lcm(opr);
			delete last;
			delete conv;
		}
		return res;
	}
};

class Expt :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr->cdr == NULL && "expected number of arguments is 2");
		Number *res = con->car, *opr = con->cdr->car, *last, *conv;
		if (res->type_<1 || res->type_>3) throw 0;
		if (opr->type_<1 || opr->type_>3) throw 0;
		last = res;
		if (res->type_ > opr->type_)
			res = res->expt(conv = res->convert(opr));
		else
			res = (conv = opr->convert(res))->expt(opr);
		delete last;
		delete conv;
		return res;
	}
};

class Sqrt :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->sqt();
	}
};

class Numerator :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->num();
	}
};

class Denominator :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->den();
	}
};

class Floor :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->flo();
	}
};

class Ceiling :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->cei();
	}
};

class Truncate :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->tru();
	}
};

class Round :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->rou();
	}
};

class Toexact :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->toexact();
	}
};

class Toinexact :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->toinexact();
	}
};

class Max :public Opt {
	Number *calc(Cons *con){
		Number *res = con->car;
		Number *last;
		for (; con; con = con->cdr){
			if (con->car->type_>3 || con->car->type_<1) throw 0;	
			Number *opr = con->car, *conv;
			last = res;
			if (res->type_ > opr->type_) res = res->maxi(conv = res->convert(opr));
			else res = (conv = opr->convert(res))->maxi(opr);
			delete last;
			delete conv;
		}
		return res;
	}
};

class Min :public Opt {
	Number *calc(Cons *con){
		Number *res = con->car;
		Number *last;
		for (; con; con = con->cdr){
			if (con->car->type_>3 || con->car->type_<1) throw 0;
			Number *opr = con->car, *conv;
			last = res;
			if (res->type_ > opr->type_) res = res->mini(conv = res->convert(opr));
			else res = (conv = opr->convert(res))->mini(opr);
			delete last;
			delete conv;
		}
		return res;
	}
};

class Sin :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->sinx();
	}
};

class Cos :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->cosx();
	}
};

class Tan :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->tanx();
	}
};

class Asin :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->asinx();
	}
};

class Acos :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->acosx();
	}
};

class Atan :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->atanx();
	}
};

class Exp :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->expx();
	}
};

class Log :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->logx();
	}
};

class Make_rectangular :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr->cdr == NULL && "expected number of arguments is 2");
		Number *res = con->car, *opr = con->cdr->car, *last, *conv;
		if (res->type_<1 || res->type_>2) throw 0;
		if (opr->type_<1 || opr->type_>2) throw 0;
		last = res;
		if (res->type_ > opr->type_)
			res = res->makerectangular(conv = res->convert(opr));
		else
			res = (conv = opr->convert(res))->makerectangular(opr);
		delete last;
		delete conv;
		return res;
	}
};

class Make_polar :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr->cdr == NULL && "expected number of arguments is 2");
		Number *res = con->car, *opr = con->cdr->car, *last, *conv;
		if (res->type_<1 || res->type_>2) throw 0;
		if (opr->type_<1 || opr->type_>2) throw 0;
		last = res;
		if (res->type_ > opr->type_)
			res = res->makepolar(conv = res->convert(opr));
		else
			res = (conv = opr->convert(res))->makepolar(opr);
		delete last;
		delete conv;
		return res;
	}
};

class Realpart :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->realpart();
	}
};

class Imagpart :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->cdr != NULL) throw 0;
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->imagpart();
	}
};

class Magnitude :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->mag();
	}
};

class Angle :public Opt{
	Number *calc(Cons *con){
		assert(con->cdr == NULL && "expected number of arguments is 1");
		if (con->car->type_<1 || con->car->type_>3) throw 0;
		return con->car->ang();
	}
};
