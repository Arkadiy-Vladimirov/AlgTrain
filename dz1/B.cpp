#include <iostream>

class Point {
    friend std::istream& operator>>(std::istream &charinput, Point &pnt);
    int x, y;
public:
    Point(int xinit = 0, int yinit = 0) : x(xinit), y(yinit) {} 
    int get_x() const { return x; }
    int get_y() const { return y; }
};

std::istream& operator>>(std::istream &charinput, Point &pnt) {
    charinput >> pnt.x;
    charinput >> pnt.y;
    return charinput;
}

Point operator-(const Point& a, const Point& b) {
    return Point(a.get_x() - b.get_x(), a.get_y() - b.get_y());
}

bool operator==(const Point& a, const Point& b) { //equivalence (may be oppositely directed)
    return ((a.get_x() == b.get_x()) && (a.get_y() == b.get_y())) || ((a.get_x() == -b.get_x()) && (a.get_y() == -b.get_y()));
}

//check if there are two pairs of points generating two parallel segmemts of same length 

int main() {
    int N;
    Point a,b,c,d;

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> a >> b >> c >> d;
        if ((a-b) == (c-d)) {
            std::cout << "YES\n";
        } else if ((a-c) == (b-d)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}