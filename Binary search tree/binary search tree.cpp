#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
	int data;
	node*left;
	node*right;
	
	node(int d)
	{
		data=d;
	    left=right=nullptr;
		}
	};
	
node*built_bst_tree(node*root,int d)
{
	if(root==nullptr)
	{
		return new node(d);
		}
	
	if(d<root->data)
		root->left=built_bst_tree(root->left,d);
	else
		root->right=built_bst_tree(root->right,d);
	
	return root;
	}
	
node* built()
{
	int d;
	cin>>d;
	
	node*root=nullptr;
	while(d!=-1)
	{
		root=built_bst_tree(root,d);
		cin>>d;
		}
	return root;
	}

void inorder_print(node *root)
{
	//base case
	if(root==nullptr)
		return;
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
	return;
	}
	
	
	
void bfs(node * root)
{
	queue<node*>q;
	
	q.push(root);
	q.push(nullptr);
	while(!q.empty())
	{
		node *f=q.front();
		if(f==nullptr)
		{	
		q.pop();
		cout<<endl;
		if(!q.empty())
			q.push(nullptr);
		    }
		else
		{
			q.pop();
		       cout<<f->data<<" ";
		       if(f->left)
		       {
				  q.push(f->left);
			      }
			   if(f->right)
		       {
			     q.push(f->right);
		     	 }
		}
	}
		
		return;
	}
	
bool search(node*root,int d)
{
	if(root==nullptr)
		return false;
	
	if(root->data==d)
		return true;
		
	if(d<root->data)
		return search(root->left,d);
	else
		return search(root->right,d);
	}
	
node* delete_in_bst(node*root,int key)
{
	//base case
	if(root==nullptr)
		return nullptr;
	else if(key<root->data)
	{
		root->left=delete_in_bst(root->left,key);
		return root;
		}
	else if(key==root->data)
	{
		// 0 child is present
		if(root->left==nullptr && root->right==nullptr)
		{
			delete root;
			return nullptr;
			}
		// only 1 child is present
		if(root->left!=nullptr && root->right== nullptr)
		{
			node *temp =root->left;
			delete root;
			return temp;
			}
		if(root->left==nullptr && root->right!= nullptr)
		{
			node *temp =root->right;
			delete root;
			return temp;
			}
		// both children are present
		if(root->left!=nullptr && root->right!= nullptr)
		{
			node* replace=root->right;
			while(replace->left!=nullptr)
			{
				replace=replace->left;
				}
			root->data=replace->data;
			root->right=delete_in_bst(root->right,replace->data);
			return root;
			}
		}
	else if(key>root->data)
	{
		root->right=delete_in_bst(root->right,key);
		return root;
		}
		
	
	}

	


int main()
{
	node*root=built();
	bfs(root);
	
	
	
	
	return 0;
	}