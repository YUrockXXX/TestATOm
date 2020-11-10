#include <iostream>

int main(){
        double N = 0, A = 0, B = 0, X = 0, Y = 0;

        std::cin >> N >> A >> B >> X >> Y;

        X /= 100;
        Y /= 100;

        if      (N > B) {N *= (1-Y);}
        else if (N > A) {N *= (1-X);}

        std::cout << N;
}
