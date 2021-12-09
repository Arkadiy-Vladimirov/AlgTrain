#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    if X != S^l (where l > 1)
    then 
        -find the first i: X[i:n) = Z[0:n-i)
        -Z' = Z[n-i:end)
        -determine max k so that Z' = X^k Y
    else
        -do the same with S (X == S^l, l - min).

    Thus we have to determine l. Notice that
        X = S^l iff X sh l == X 
*/

int main() {
    std::string X,Y,Z;
    std::cin >> X >> Z;
    int n = X.length();

    //[1:n] generator
    auto seq1_gen = [cnt=0]() mutable 
        {return ++cnt;};
    //true if X shl l == X
    auto shlX_eq_X = [&X] (int l) 
        {return ((X.substr(l) + X.substr(0,l)) == X);};

    //generate range [1:n]
    std::vector<int> l_range;
    std::generate_n(std::back_inserter(l_range), n, seq1_gen);


    //find minimum l in [1:n] so that X == S^l_______________________
    int l = *std::find_if(l_range.begin(), l_range.end(), shlX_eq_X);
    //_______________________________________________________________
    
    X = X.substr(0,l);
    n = X.length();

    //[0:n-1] generator
    auto seq0_gen = [cnt=-1]() mutable 
        {return ++cnt;};
    //true if X[i:n) = Z[0:n-i)
    auto Xend_eq_Zbeg = [&X,&Z,n] (int i)
        {return (X.substr(i,n) == Z.substr(0,n-i));};
    std::vector<int> idx;
    std::generate_n(std::back_inserter(idx), n, seq0_gen);

    //find the first i: X[i:n) = Z[0:n-i)__________________
    auto p = find_if(idx.begin(), idx.end(), Xend_eq_Zbeg);
    //_____________________________________________________

    if (p == idx.end()) {
        std::cout << Z;
        return 0;
    }
    
    Y = Z.substr(n-*p);
    while (Y.substr(0,n) == X) {
        Y = Y.substr(n);
    }

    std::cout << Y;
}