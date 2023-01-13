#include<iostream>
#include<vector>
using namespace std;
int main(){
    int V,E;
    cout<<"How many vertices are there in the graph? "<<endl;
    cin>>V;
    cout<<"How many edges are there in the graph? "<<endl;
    cin>>E;
    vector<int> adjlist[V];
    for(int i=1;i<=E;i++){
        int a,b;
        cout<<"enter end points of edge"<<i;
        cin>>a>>b;
        adjlist[a]
    }
}
