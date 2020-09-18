#include<bits/stdc++.h>

using namespace std;

template<typename T>
class BIT{
    private:
    vector<T> vs;
    int n;

    public: 
    BIT(int n){
        this->vs.assign(n+1, 0);
        this->n = n;
    }

    void update(T i, T delta){
        for (;i <= n;i += i&(-i)) vs[i] += delta;
    }

    T query(T i){
        T sum = 0;
        for (;i;i -= i&(-i)) sum += vs[i];
		return sum;
    }
};