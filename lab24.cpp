#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber operator+(double x, const ComplexNumber &c){
	return ComplexNumber(x+c.real,c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator-(double x, const ComplexNumber &c){
	return ComplexNumber(x-c.real,-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag) , (real*c.imag)+(imag*c.real));
}

ComplexNumber operator*(double x, const ComplexNumber &c){
	return ComplexNumber((x*c.real),(x*c.imag));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)) ,
	(-(real*c.imag)+(imag*c.real))/(pow(c.real,2)+pow(c.imag,2)));
}

ComplexNumber operator/(double x, const ComplexNumber &c){
	return ComplexNumber((x*c.real)/(pow(c.real,2)+pow(c.imag,2)),
	(-(x*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag) return 1;
	else return 0;
}

ComplexNumber operator==(double x, const ComplexNumber &c){
	if(x == c.real && c.imag == 0) return 1;
	else return 0;
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
	return (atan2(imag,real))*(180/M_PI);
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
	if(c.real==0){
	    if(c.imag==0){
            os << 0;
        }
        else os << c.imag << "i";
	}
	else if(c.imag>0) os << c.real << "+" << c.imag << "i";
	else if(c.imag==0) os << c.real;
	else if(c.imag<0) os << c.real << c.imag << "i";
	return os;
}
