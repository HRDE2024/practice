/*
提供一个vector高效转移的方案
*/
#include<iostream>
#include<vector>
using namespace std;


void printVec(vector<int> vec){
    if(vec.size() == 0)
        return;

    for(int num: vec){
        cout<<num<<" ";
    }
    cout<<"\n";
}

int main(){
    vector<int> m1, m2;
    for(int i = 0; i<10; i++){
        m1.push_back(i);
    }

    printVec(m1);

    
    
    return 0;
}

