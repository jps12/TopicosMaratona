#include<bits/stdc++.h>

using namespace std;


template<class T>
class Matrix{
    public:
    vector<vector<T>> v;
    int l, c;

    Matrix(int l, int c){
        v.resize(l, vector<T>(c));
        this->l = l;
        this->c  = c;
    }

    void m_null(){
        for (int i=0; i<l; i++){
            for (int j=0; j<c;j++){
                v[i][j] = 0;
            }
        }
    }

    Matrix operator*(Matrix b){
        if (c != b.l) {
            b.m_null();
            return b;
        }
        Matrix ans(l, b.c);

        for (int i=0; i<l; i++){
            for (int j=0; j<b.c; j++){
                T sum = 0;
                for (int k=0; k<c; k++){
                    sum += v[i][k]*b.v[k][j];
                }
                ans.v[i][j] = sum;
            }
        }
        return ans;
    }

    void iden(){
        for (int i=0; i<l; i++){
            for (int j=0; j<c; j++){
                T& val = v[i][j];
                if (i == j) val = 1;
                else val = 0;
            }
        }
    }
    void print(){
        for (int i=0; i<l; i++){
            for (int j=0; j<c; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};