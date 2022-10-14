#include<bits/stdc++.h>
using namespace std;


// Program to find number of connected component using disjoint set union.
const int N = 100000;
int parent[N],siz[N];
int findParent(int i)
{
    if (i == parent[i])
        return i;
    return parent[i] = findParent(parent[i]);
}
void unionNodes(int a,int b)
{
    int parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    if(siz[parent_a]>=siz[parent_b]){
        swap(parent_a,parent_b);
    }
    siz[parent_b]+=siz[parent_a];
    parent[parent_a]=parent_b;
    return;
}
void cleardsu(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        siz[i]=1;
    }
}
int main(){
	int n; cin>>n;
	cleardsu(n);
	for(int i=0;i<n;i++){
		// add edge between node a and node b
		int a,b; cin>>a>>b;
		unionNodes(a,b);
	}
	set<int>st;
	for(int i=0;i<n;i++){
		st.insert(findParent(i));
	}
	cout<<st.size()<<endl;
}
