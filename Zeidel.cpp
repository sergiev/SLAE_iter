//
// Created by s3 on 03.04.18.
//
#include "refers.h"

void zMethod(vector<vector<double>> a, vector<double> b, vector<double> x){
    cout<<endl<<"Zeidel method.\nStart point:";
    showvector(x);
    vector<vector<double>> c=a;
    vector<double> d=b,xold=x;
    for (int i=0;i<b.size();i++) d[i]=b[i]/a[i][i];
    for (int i=0;i<c.size();i++){
        for (int j=0;j<c.size();j++){
            c[i][j]=(i==j)? 0.0 : -1*a[i][j]/a[i][i];
        }
    }
    double diff=5;
    double dold;
    int k=0;
    while(diff>EPS){
        xold=x;
        for (int i=0;i<c.size();i++){
            x[i]=0;
            for (int j=0;j<c.size();j++){
                x[i]+=c[i][j]*x[j];
            }
            x[i]+=d[i];
        }
        dold=diff;
        diff=0;
        for (int i=0;i<x.size();i++){
            diff+=abs(xold[i]-x[i]);
        }
        if (abs(dold-diff)<EPS/100) break;
        k++;
        if (k%100<2) {
            cout << "Iteration " << k << endl;
            showvector(x);
            cout<<"Difference="<<diff<<endl;
        }
    }
    cout<<"The root is:";
    showvector(x);
}