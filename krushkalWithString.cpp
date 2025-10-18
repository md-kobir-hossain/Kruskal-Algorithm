#include<bits/stdc++.h>
using namespace std;

int par[500];
int len[500];
pair<int, pair<int, int>> edges[100];
map<string, int>mp;


void ini(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        len[i]=1;
    }
}

int findSet(int x){
    if(par[x]==x)
        return x;

    int r=findSet(par[x]);
    par[x]=r;
    return r;
}

void Union(int x,int y){
    int x1=findSet(x);
    int y1=findSet(y);

    if(x1==y1)
        return;
    if(len[x1]>len[y1]){
        par[y1]=x1;
        len[x1]=len[x1]+len[y1];
    }else{
        par[x1]=y1;
        len[y1]=len[x1]+len[y1];
    }
}

int krushkal(int n,int e){
    sort(edges,edges+e);
    int sum=0;
    for(int i=0;i<n;i++){
        int u=edges[i].second.first;
        int v=edges[i].second.second;
        int w=edges[i].first;

        if(findSet(u)!=findSet(v)){
            Union(u,v);
            sum+=w;
        }
    }
    return sum;

}



int main(){
    int e;
    cin>>e;
    int idCounter=0;

    vector<tuple<string,string,int>> enterEdges;

    for(int i=0;i<e;i++){
        string u;
        string v;
        int w;

        cin>>u>>v>>w;

        if(mp.find(u)==mp.end())
            mp[u]=idCounter++;
        if(mp.find(v)==mp.end())
            mp[v]=idCounter++;

        enterEdges.push_back({u,v,w});
    }

    int n=idCounter;
    ini(n);

    for(int i=0;i<e;i++){
        string u=get<0>(enterEdges[i]);
        string v=get<1>(enterEdges[i]);
        int w= get<2>(enterEdges[i]);

        edges[i]= {w,{mp[u],mp[v]}};
    }

    int w=krushkal(n,e);
    cout<<w;


return 0;
}

/*
Example Input:
11
4 3 1
4 5 13
0 1 2
6 5 21
0 6 8
0 5 14
2 5 17
2 4 5
1 2 19
2 3 9
1 5 25

OR (string version):
6
A B 4
B C 6
A C 5
C D 7
B D 8
A D 10
*/
