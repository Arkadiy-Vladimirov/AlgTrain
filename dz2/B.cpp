#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    //static int i = 0;
    std::string X,Y,Z;
    std::cin >> X >> Z;

    int n = X.length();

    std::vector<int> idx;
    for (int i = 0; i < n; ++i) {
        idx.push_back(i);
    }

    auto p = find_if(idx.begin(), idx.end(), [&X,&Z,n] (int i) {return (X.substr(i,n) == Z.substr(0,n-i)); });

    std::cout << X.substr(*p,n);

    return 0;
}
    

    /*int n = X.length();
    int i = 0;

    while ((i < n) && (X.substr(i,n) != Z.substr(0,n-i))) {
        ++i;
    }*/

    /*
    #include <algorithm>
    a = 1:n
    p = find_if(a.begin(),a.end(),
    [&X,&Z](int i)->bool {return X.substr(i,n) == Z.substr(0,n-i); }
    }
    */

    //std::cout << X.substr(i,n);
