#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    static int i = 0;
    std::string X,Y,Z;
    std::cin >> X >> Z;

    int n = X.length();
    auto seq_gen = [cnt=0]() mutable{return ++cnt;};
    auto Xend_eq_Zbeg = [&X,&Z,n] (int i)
                                    {return (X.substr(i,n) == Z.substr(0,n-i));};

    //generate array of indices
    std::vector<int> idx(n);
    std::generate(idx.begin(),idx.end(),seq_gen);
    //find i: X[i:n) = Z[0:n-i)
    auto p = find_if(idx.begin(), idx.end(), Xend_eq_Zbeg);

    std::cout << X.substr(*p,n);
    return 0;
}