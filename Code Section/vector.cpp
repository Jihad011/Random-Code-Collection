#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
                v.push_back(4);
                v.push_back(5);
                cout<<v.at(0)<<" ";
                cout<<v.at(1)<<endl;
                for(int i=0; i<v.size(); i++)
{
    cout<<v[i]<<" ";
    }
    cout<<endl;
        cout<<v.front()<<endl;
        cout<<v.back()<<endl;
        cout<<v.size()<<endl;
        v.clear();
        cout<<v.size()<<endl;
    if(v.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;
        v.pop_back();
        //v.erase(v.begin()+1)
                for(int i=0; i<v.size(); i++)
{
    cout<<v[i]<<" ";
    }
cout<<endl;

}

