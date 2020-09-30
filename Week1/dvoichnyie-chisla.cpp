#include <iostream>
#include <vector>

int main(){
        int N = 0;

        std::cin >> N;
        std::vector<int> v;

        while(N != 0) {
                v.push_back(N % 2);
                N /= 2;
        }
        int flag = 0;
        for(int i = v.size() - 1; i >= 0; i--) {
                if (v[i] != 0) {
                        std::cout << v[i];
                        flag = 1;
                }
                if (v[i] == 0 && flag != 0) {
                        std::cout << v[i];
                }
        }

        return 0;
}
