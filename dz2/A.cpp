#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    int N, K, a_i;
    std::cin >> N >> K;

    std::vector<long> a;

    for (int i = 0; i < N; ++i) {
        std::cin >> a_i;
        a.push_back(a_i); 
    }

    std::cout << *std::max_element(a.begin(), a.end()) - *std::min_element(a.begin(), a.end());

    return 0;
}
