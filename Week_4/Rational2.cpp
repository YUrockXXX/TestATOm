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


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
