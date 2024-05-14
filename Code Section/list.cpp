#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>li;
    li.push_back(12);
        li.push_back(128);
    li.push_back(129);
    li.push_back(1299);
    li.pop_back();
    //i.clear(); for clearing the list
list<int>::iterator it;

    for(it=li.begin();it!=li.end();it++){
    cout<<*it<<" ";


    }
cout<<endl;
}
