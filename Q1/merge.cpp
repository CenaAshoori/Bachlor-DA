#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> merge_two(vector<int> a , vector<int> b){
     int i =0  , j =0;
     int n = a.size();
     int m = b.size();
     vector<int> c;

     while(i<n && j<m){
        if (a[i]<=b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
     }
     while(i<n){
        c.push_back(a[i++]);
     }
     while(j<m){
        c.push_back(b[j++]);
     }
     return c;

 }
