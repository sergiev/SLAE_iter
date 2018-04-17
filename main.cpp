#include "refers.h"

int main() {
    int n;
    cout << "We're about to solve the system of linear algebraic equations.\nEnter N: ";
    cin >> n;
    vector<vector<double>> slau(3, vector<double>(3));
    cout << "Elements of matrix A:";
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) slau[i][j] = (i == j) ? n + 2 * (i + 1) : 1;
    showmatrix(slau);
    cout << "Elements of vector B:";
    vector<double> b = {n + 4, n + 6, n + 8};
    showvector(b);
    vector<double> x = {2, 1, 8};
    zMethod(slau, b, x);
    gMethod(slau, b);
    cout << "Enter the size of bad system:";
    int s;
    cin >> s;
    vector<vector<double>> bad(s, vector<double>(s));
    vector<vector<double>> freebad(1,vector<double>(s));
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) bad[i][j] = (i > j) ? U * n : (i == j) ? 1 + U * n : -1 - U * n;
        freebad[0][i]=(i<s-1)?-1:1+EPS;
    }
    showmatrix(bad);
    gMethod(bad,freebad[0]);
    vector<double> a(s);
    for (int i=0;i<a.size();i++) a[i]=pow(2,i);
    vector<vector<double>> ata=monm(transpone(bad),bad);
    vector<double> btb=transpone(monm(transpone(bad),transpone(freebad)))[0];
    zMethod(ata,btb,a);
    return 0;
}