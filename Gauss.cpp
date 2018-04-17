//
// Created by s3 on 03.04.18.
//
#include "refers.h"
vector<double> sum (vector<double> v1, vector<double> v2)
{
    vector<double> r=v1;
    for (int i=0;i<r.size();i++) r[i]+=v2[i];
    return r;
}
vector<double> mult (double v1, vector<double> v2)
{
    vector<double> r=v2;
    for (int i=0;i<r.size();i++) r[i]*=v1;
    return r;
}
void gMethod(vector<vector<double>> a, vector<double> b){
    cout<<endl<<"Gauss' method.\nTriangle-like matrix is:";
    vector<vector<double>> g=a;
    vector<double> x(g.size());
    double m;
    for (int i=0;i<g.size();i++) g[i].push_back(b[i]);
    for (int i=0;i<g.size();i++) {
        for (int j=i+1;j<g.size();j++) {
            m = -1 * g[j][i] / g[i][i];
            g[j] = sum (mult(m,g[i]),g[j]);
        }
    }
    showmatrix(g);
    for (int i=g.size()-1;i>=0;i--){
        x[i]=g[i][x.size()];
        for (int j=g[i].size()-1;j>i;j--) x[i]-=g[i][j]*x[j];
        x[i]/=g[i][i];
    }
    cout<<"The root is:";
    showvector(x);
}
