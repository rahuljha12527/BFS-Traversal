#include<queue>
#include<iostream>

using namespace std;

void printBFS(int **edges,int n,int sv,bool *visited){

    queue<int> pendingNodes;

    pendingNodes.push(sv);
    visited[sv]=true;
    while(!pendingNodes.empty()){
        
        int node=pendingNodes.front();
        pendingNodes.pop();
        cout<<node<<" ";
        

        for(int i=0;i<n;i++){
            
            if(i==node){
                continue;
            }

          if(edges[node][i]==1 && !visited[i]){
              pendingNodes.push(i);
              visited[i]=true;

          }
        }

    }
}

void BFS(int **edges,int n){

    bool *visited=new bool[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
          printBFS(edges,n,i,visited);
        }
    }

    delete []visited
int main(){
    int n;
    int e;
    cin>>n>>e;
    int **edges=new int*[n];

    for(int i=0;i<n;i++){

        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
        
}

   BFS(edges,n);

   for(int i=0;i<n;i++){
       delete  edges[i];
   }

   delete [] edges;
}