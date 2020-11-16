#include <iostream>
#include <math.h>
#include <exception>
#include <stdexcept>

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
    Rational(int num) : numerator(num),denominator(1) {}
    Rational(int num, int den) {
        if (den == 0)
        {
            throw invalid_argument("Invalid argument");
        }
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
    void SetNumenator(int num){
        numerator = num;
    }
    void SetDenominator (int den){
        denominator = den;
    }
    friend Rational operator+(Rational lhs, Rational rhs);
    friend bool     operator==(Rational lhs, Rational rhs);
    friend Rational operator-(Rational lhs, Rational rhs);
    friend Rational operator*(Rational lhs, Rational rhs);
    friend Rational operator/(Rational lhs, Rational rhs);
    friend ostream& operator<<(ostream& out, const Rational& rat);
    friend istream& operator>>(istream& input, const Rational& rat);
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
    if (rhs.Numerator() == 0)
    {
        throw domain_error("Division by zero");
    }
    Rational temp(lhs.Numerator()*rhs.Denominator(),
                  lhs.Denominator()*rhs.Numerator());
    return temp;
}

ostream& operator<<(ostream& out, const Rational& rat){
    out << rat.Numerator() << "/" << rat.Denominator();
    return out;
}
istream& operator>>(istream& input,Rational& rat){
    int num = 0;
    int den = 1;
    char devide_sign ;
    if (input >> num && input >> devide_sign && input >> den && devide_sign == '/')
    {
        Rational temp(num,den);
        rat = temp;
    }
    else {
        Rational temp(1,0);

    }
    return input;

}
bool operator<(const Rational lhs,const Rational rhs) {
    return (lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator()) < 0 ? true : false;
}
bool operator>(const Rational lhs,const Rational rhs) {
    return (lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator()) > 0 ? true : false;

}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& exc) {
        cout << exc.what() << endl;
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error& exc) {
        cout << exc.what() << endl;
    }

    cout << "OK" << endl;
    return 0;
}
