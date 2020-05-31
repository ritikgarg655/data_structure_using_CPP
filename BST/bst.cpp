#include<bits/stdc++.h>
using namespace std;

class bst
{
private:
	struct node{
		int data;
		node *left;
		node *right;
	};
	int num_node;
	node* root;
	void add(int value,node *n){
		// if(n==NULL){
		// 	// cout<<"-1";
		// 	n = (node *)malloc(sizeof(node));
		// 	n->data = value;
		// 	n->left = NULL;
		// 	n->right = NULL;
		// 	num_node++;
		// }
		// else{
		{
			if(n->data>value){
				if(n->left==NULL){
					node *ne = (node *)malloc(sizeof(node));
					ne->data = value;
					ne->left = NULL;
					ne->right = NULL;
					num_node++;
					n->left = ne;
					return;
				}
				add(value,n->left);
			}
			else if(n->data<value){
				if(n->right==NULL){
					node *ne = (node *)malloc(sizeof(node));
					ne->data = value;
					ne->left = NULL;
					ne->right = NULL;
					num_node++;
					n->right = ne;
					return;
				}
				add(value,n->right);
			}
			else {
				return;
			}
		}
	}
	node* present(int value){
		node* next_root = root;
		while(next_root!=NULL){
			if(next_root->data==value){
				return next_root;
			}
			else if(next_root->data>value){
				next_root = next_root->left;
			}
			else{
				next_root = next_root->right;
			}
		}
		return next_root;
	}
public:
	bst(){
		root = NULL;
		num_node = 0;
	}
	void add(int value){
		if(root==NULL){
			root = (node *)malloc(sizeof(node));
			root->data = value;
			root->left = NULL;
			root->right = NULL;	
			num_node++;
		}
		else{
			add(value,root);
		}
	}
	void remove(int value){
		node *n = present(value);
		node *parent = NULL;
		node* next_root = root;
		while(next_root!=NULL){
			if(next_root->data==value){
				break;
			}
			else if(next_root->data>value){
				parent = next_root;
				next_root = next_root->left;
			}
			else{
				parent = next_root;
				next_root = next_root->right;
			}
		}
		if(n!=NULL){
			// cout<<n->data;
			if(n->left == NULL and n->right!=NULL){
				node *next = n->right;
				node *prev = n;
				while(1){
					if(next->left==NULL){
						break;
					}
					else{
						prev = next;
					}
					next = next->left;
				}
				n->data = next->data;
				if(prev==n){
					n->right = (n->right)->right;
				}
				else
				prev->left = NULL;
				free(next);
				num_node--;
			}
			else if(n->right ==NULL and n->left==NULL){
				n = NULL;
				free(n);
				if(parent==NULL){
					root = NULL;
				}
				else{
					if((parent->right)->data == value)
						parent->right = NULL;
					else
						parent->left = NULL;
				}
				num_node--;
			}	
			else{
				node *next = n->left;
				node *prev = n;
				while(1){
					if(next->right==NULL)
						break;
					else
						prev = next;
					next = next->right;
				}
				n->data = next->data;
				if(prev==n){
					n->left = (n->left)->left;
				}
				else
					prev->right = NULL;
				free(next);
				num_node--;
			}
		}
		else{
			cout<<"Value is not present."<<endl;
		}
	}
	void print_tree(){
		node *n = root;
		queue<node *> q;
		q.push(n);
		cout<<"TREE: ";
		while(!q.empty()){
			node *next = q.front();
			q.pop();
			// if(next==NULL){
			// 	continue;
			// }
			cout<<(next->data)<<" ";
			if(next->left!=NULL){
				q.push(next->left);
			}
			if(next->right!=NULL){
				q.push(next->right);
			}
		} 
		cout<<endl;
	}
};

int main(){
	bst b;
	b.add(1);
	b.add(2);
	b.add(3);
	b.add(4);
	b.add(5);
	b.add(6);
	b.print_tree();
	b.remove(4);
	b.remove(3);
	b.print_tree();
}