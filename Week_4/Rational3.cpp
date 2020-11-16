#include <iostream>
#include <math.h>

using namespace std;

int gcd (int a, int b) {
    while (a!=0 && b!=0) {
        if (a>b) {
            a=a%b;
        }
        else b=b%a;
    }
    return a+b;
}

class Rational {
public:
    Rational(): numerator(0),denominator(1) {}

    Rational(int num, int den) {
        if (num == 0)
        {
            den = 1;
        }
        int gcdForRational = gcd(abs(num),abs(den));
        if ((num < 0 && den < 0) || (num > 0 && den < 0))
        {
            num *= -1;
            den *= -1;
        }
        numerator = num/gcdForRational;
        denominator = den/gcdForRational;

    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};
bool operator==(Rational lhs, Rational rhs){
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
        return true;
    else
        return false;
}
Rational operator+(Rational lhs, Rational rhs){
    Rational temp(lhs.Numerator()*rhs.Denominator()+lhs.Denominator()*rhs.Numerator(),
                  lhs.Denominator()*rhs.Denominator());
    return temp;
}
Rational operator-(Rational lhs, Rational rhs){
    Rational temp(lhs.Numerator()*rhs.Denominator()-lhs.Denominator()*rhs.Numerator(),
                  lhs.Denominator()*rhs.Denominator());
    return temp;
}
Rational operator*(Rational lhs, Rational rhs){
    Rational temp(lhs.Numerator()*rhs.Numerator(),
                  lhs.Denominator()*rhs.Denominator());
    return temp;
}
Rational operator/(Rational lhs, Rational rhs){
    Rational temp(lhs.Numerator()*rhs.Denominator(),
                  lhs.Denominator()*rhs.Numerator());
    return temp;
}


int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
