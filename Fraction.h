#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <numeric> 

using namespace std;

class Fraction {
public:
    int num, den;

    Fraction(int n = 0, int d = 1) {
		this->num = n;
		this->den = d;
        reduce();
    }

    int gcd(int a, int b)
    {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }


    Fraction operator*(Fraction& f){
        Fraction temp(num * f.num, den * f.den);
        temp.reduce();
        return temp;
    }

    Fraction operator+(Fraction& f){
        Fraction temp(num * f.den + den * f.num, den * f.den);
        temp.reduce();
        return temp;
    }
};