#include<iostream>
#include<vector>
#include<queue>
// #include<pair>
using namespace std;




int dfs_visit(int i,vector<int>&visited,vector<int>adjlist[],int ele){
    cout<<i;
    visited[i]=1;
    for(int j=0;j<adjlist[i].size();j++){
        if(visited[adjlist[i][j]]==0){
            ele++;
            ele=dfs_visit(adjlist[i][j],visited,adjlist,ele);
        }
    }
    return ele;
}

void dfs(vector<int>adjlist[],int v){
    vector<int>visited(v,0);
    vector<int>elements;
    int countg=0;
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            countg=countg+1;
            int ele=1;
            ele=dfs_visit(i,visited,adjlist,ele);
            elements.push_back(ele);
        }
    }
    cout<<endl<<"no of connected compo="<<countg;
    cout<<"elements in comp"<<endl;
    for(int i=0;i<countg;i++){
        cout<<elements[i]<<endl;
    }



}

int main(){
    int DAT_in[26]={0};
    int DAT_out[26]={0};
    int v,e;
    cout<<"how many vertices in graph";
    cin>>v;
    cout<<"how many edges in graph";
    cin>>e;
    vector<int>adjlist[v];
    vector<int>indeg(v);
    vector<int>outdeg(v);
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end points of edge"<<i<<":";
        cin>>a>>b;
        adjlist[a].push_back(b);
        DAT_in[b]++;

    }
    cout<<endl<<"adj list"<<endl;
    for(int i=0;i<v;i++){
        outdeg[i]=adjlist[i].size();
        cout<<i<<":";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<",";
            indeg[adjlist[i][j]]++;

        }
        cout<<"   outdegree of "<<i<<" = "<<outdeg[i];
        cout<<"   indegree of "<<i<<" = "<<DAT_in[i];

        cout<<endl;
    }
    cout<<endl;

   dfs(adjlist,v);
}

