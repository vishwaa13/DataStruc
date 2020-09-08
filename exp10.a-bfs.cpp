#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000];
vector<int> visited(1000,0);
void bfs(int cur,int n){
	queue<int>q;
	q.push(cur);
	visited[cur]=1;
	while(!q.empty()){
		int out = q.front();
		visited[out]=1;
		cout<<out<<"\t";
		q.pop();
		for(auto x: g[out]){
			if(!visited[x]){
				// cout<<"pushing  "<<x<<endl;
				q.push(x);
				visited[x]=1;
			}
		}
	}

}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		// v1--;
		// v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	bfs(2,n);

}
