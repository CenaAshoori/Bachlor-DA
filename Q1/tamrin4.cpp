#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> merge_two(vector<int> i , vector<int> j);
vector<int> sortK(vector<int>& vec , int k);

int tamrin4(){

    vector<int> vec1 ={1,2,3,4,5,6,7};
    vector<int> vec2 ={9,10,11,12,13,14,15};
    vector<int> vec3 ={1,2,5,14,15,16,17};
    vector<int> m1 = merge_two(vec1 , vec2);
    vector<int> result = merge_two(m1 , vec3);

    for(auto item : result){
        cout<<item<<" ";
    }


return 0;
}


