#include <iostream>
#include <string>
using namespace std;

class Complex;
class Calculator{
    public:
    int add(int a, int b){
        return a+b;
    }

    Complex addCmplx(Complex c1, Complex c2);
};
class Complex{
    int real;
    int complex;
    friend Complex Calculator :: addCmplx(Complex c1, Complex c2);
    public:
    int setCmplx(int r, int c){
        real = r;
        complex = c;
        displayCmplx();
        return real,complex;
    }

    void displayCmplx(){
        cout<< real <<" + "<<complex<<"i"<<endl;
    }
};

Complex Calculator :: addCmplx(Complex c1, Complex c2){
        Complex c3;
        c3.setCmplx((c1.real+c2.real),(c1.complex+c2.complex));
        return c3;
    }



int main(int argc, char const *argv[])
{
    Complex c1, c2;
    c1.setCmplx(1,4);
    c2.setCmplx(21,44);

    Calculator calc;
    calc.addCmplx(c1,c2);
    return 0;
}
