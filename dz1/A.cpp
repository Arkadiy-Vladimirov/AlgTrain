#include <iostream>

// (ax+b)/(cx+d) = 0; a,b,c,d, x \in \mathbb{Z}; x - ? 

int main() {
    int a, b, c, d;
    int x;
    std::cin >> a >> b >> c >> d;

// ax == b && cx != d
    if (a != 0) {
        if (b%a == 0) {
            x = -b/a;
            if (c*x+d == 0) {
                std::cout << "NO";
            } else {
                std::cout << x;
            }
        } else {
            std::cout << "NO";
        }
    } else {
        if (b == 0) {
            std::cout << "INF";
        } else {
            std::cout << "NO";
        }
    }

    return 0;
}