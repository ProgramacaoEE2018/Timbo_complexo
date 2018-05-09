#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

class Complexo{
private:
    float real, im;
public:
    Complexo(float a, float b);

    float Modulo(){
        return sqrt(real*real+im*im);
    }

    Complexo Conjugado(){
        return Complexo(real, (-1)*im);
    }

    Complexo operator-(const Complexo& theta){
        return Complexo(real - theta.real, im - theta.im);
    }

    Complexo operator+(const Complexo& theta){
        return Complexo(real + theta.real, im + theta.im);
    }

    Complexo operator*(const Complexo& theta){
        return Complexo(real*theta.real-im*theta.im, real*theta.im+im*theta.real);
    }

    Complexo operator/(const Complexo& theta){
        return Complexo((real*theta.real+im*theta.im)/(theta.real*theta.real+theta.im*theta.im), (im*theta.real-real*theta.im)/(theta.real*theta.real+theta.im*theta.im));
    }

    void imprimir_cartesiana(){
        printf("%f %f\n", real, im);
    }
};

Complexo::Complexo(float a, float b){
    real = a;
    im = b;
}

int main()
{
     Complexo z1(20,21);
     Complexo z2(3,4);

     printf("%f  %f\n", z1.Modulo(), z2.Modulo());

     Complexo sum = z1+z2;
     sum.imprimir_cartesiana();

     Complexo dif = z1-z2;
     dif.imprimir_cartesiana();

     Complexo prod = z1*z2;
     prod.imprimir_cartesiana();

     Complexo div = z1/z2;
     div.imprimir_cartesiana();
}