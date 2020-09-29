#include <iostream>
#include <cmath>

int main(){
        double a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c;

        if     (a == 0 && b == 0 && c == 0) {}
        else if(a == 0 && b == 0) {}
        else if(a == 0) {
                std::cout << -c/b;
        }
        else{
                double D = b*b - 4*a*c;
                if (D < 0) {}
                else {
                        D = sqrt(D);
                        double x1 = (-b+D)/(2*a);
                        double x2 = (-b-D)/(2*a);
                        if (x1 == x2) {
                                std::cout << x1;
                        }
                        else
                                std::cout << x1 << " " << x2;
                }
        }

        return 0;
}
