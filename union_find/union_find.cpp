#include<bits/stdc++.h>
using namespace std;

class union_find
{
private:
	int *id;
	int *sz;
	int numcomponent;
	int size;
public:
	union_find(int size){
		id = (int *)malloc(sizeof(int)*size);
		sz = (int *)malloc(sizeof(int)*size);
		
		for(int i=0;i<size;i++){
			id[i] = i;
			sz[i] = 1;
		}
		
		numcomponent = size;
		this->size = size;
	}

	int find(int p){
		int root = p;
		
		while(root != id[root]){
			root = id[root];
		}

		while(p!=root){
			int next = id[root];
			id[p] = root;
			p = next;
		}

		return root;
	}
	void do_union(int p,int q){
		int root_p = find(p);
		int root_q = find(q);
		if(root_q==root_p) return;
		if(sz[root_q]<sz[root_p]){
			sz[root_p]+=sz[root_q];
			id[q] = root_p;
		}	 
		else{
			sz[root_q]+=sz[root_p];
			id[p] = root_q;
		}
		numcomponent--;
	}
};

int main(){
	union_find a(5);
	a.do_union(1,4);
	a.do_union(0,2);
}