#include <iostream>
#include <queue>

using namespace std;
class Node{
public:
	int data;
	Node *left;
	Node *right;

    Node(int d)
	{
		data=d;
		right=left=nullptr;
		};
	};


Node *built_tree(){
	int d;
	cin>>d;
	// base case(to stop making children)
	if (d==-1)
		return nullptr;
		
	// to make parent Node
	Node *root=new Node(d);
    
	// to make children
	root->left=built_tree();
	root->right=built_tree();
	
	return root;
	}

void print(Node *root){
	//base case
	if(root==nullptr)
		return;
	
	//printing data 
	cout<<root->data<<" ";
	
	//to print children by rec call
	
	print(root->left);
	
	print(root->right);
	
	return;
	}

void inorder_print(Node *root){
	//base case
	if(root==nullptr)
		return;
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
	return;
	}

void postorder_print(Node *root)
{
	//base case
	if(root==nullptr)
		return;
	postorder_print(root->left);
	postorder_print(root->right);
	cout<<root->data<<" ";
	
	return;
	}
	
int height(Node* root)
{
	if (root==nullptr)
		return 0;
		
	int x=max(height(root->left),height(root->right))+1;
	
	return x;
	}

void levelorder_print(Node*root,int k)
{
	if(root==nullptr)
		return;
	if(k==1)
	{
		cout<<root->data<<" ";
		}
	levelorder_print(root->left,k-1);
	levelorder_print(root->right,k-1);
	return;
	}
	
void all_level_print(Node *root)
{
	int h=height(root);
	
	for(int i=1;i<=h;i++)
	{
		levelorder_print(root,i);
		cout<<endl;
		}
	return;
	}
	
void bfs(Node * root)
{
	queue<Node*>q;
	
	q.push(root);
	q.push(nullptr);
	while(!q.empty())
	{
		Node *f=q.front();
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
	
int count_Nodes(Node *root)
{
	//base case
	if(root==nullptr)
		return 0;
	
	//rec case
	int small_count=1+count_Nodes(root->left)+count_Nodes(root->right);
	return small_count;
	}

int sum_Nodes(Node *root)
{
	//base case
	if(root==nullptr)
		return 0;
	
	//rec case
	int small_sum=root->data+sum_Nodes(root->left)+sum_Nodes(root->right);
	return small_sum;
	}

int diameter(Node *root)
{
	//base case
	if(root==nullptr)
		return 0;
		
		int ans1=height(root->left)+height(root->right);
		int ans2=diameter(root->left);
		int ans3=diameter(root->right);
		
		return max(ans1,max(ans2,ans3));
		
	}
	
int replace_by_sum_of_child_Node(Node* root)
{
	if(root==nullptr)
		return 0;
	if(root->left==nullptr && root->right==nullptr)
	{
		return root->data;
		}
	
	int prev_root=root->data;
	
	root->data=replace_by_sum_of_child_Node(root->left)+replace_by_sum_of_child_Node(root->right);
	return root->data+prev_root;
	}
	
class HBpair
{
public:
	int height;
	bool balanced;
	};
	
HBpair isblanced_height(Node *root)
{
	HBpair p;   
	if(root==nullptr)
	{
		p.height=1;
		p.balanced=true;
		return p;
		}
	
	HBpair left=isblanced_height(root->left);
	HBpair right=isblanced_height(root->right);
	
	p.height=max(left.height,right.height)+1;//2
	
	if(abs(left.height-right.height)<2 && left.balanced && right.balanced)
		p.balanced=true;
	else
		p.balanced=false;
		
	return p;
		
	}
	
Node* built_tree_from_array(int *a,int start,int end)
{
	if(start>end)
		return nullptr;
		
	int mid=(start + end)/2;
	Node *root=new Node(a[mid]);
	root->left=built_tree_from_array(a,start,mid-1);
	root->right=built_tree_from_array(a,mid+1,end);
	
	return root;
	
	}
	
Node* tree_from_trav(int *pre,int *in ,int start,int end)
{
	static int index=0;
	if(start>end)
		return nullptr;
	
	Node* root=new Node (pre[index]);
	int ele_idx_inorder=0;
	for(int j=0;j<=end;j++)
	{
		if(pre[index]==in[j])
		{   
			ele_idx_inorder=j;
			break;
			}
		}
		index++;
	root->left= tree_from_trav( pre,in ,start,ele_idx_inorder-1);
	root->right= tree_from_trav( pre,in ,ele_idx_inorder+1,end);
	
	return root;
	}
	
void right_view_tree(Node* root,int level)
{
	static int max_level=-1;
	
	if(root==nullptr)
		return;
	
	if(max_level<level)
	{
		cout<<root->data<<" , ";
		max_level=level;
		}
	right_view_tree(root->right,level+1);
    right_view_tree(root->left,level+1);	
	return;
	}
	
int print_at_distance_k(Node*root,Node*target,int dis)
{
	if(root==nullptr)
		return -1;
	
	if(root==target)
	{
		levelorder_print(target,dis+1);
		return 0;
		}
    
	int DL=print_at_distance_k(root->right,target,dis);
	
	if(DL!=-1)
	{
		if(DL+1==dis)
		{
			cout<<root->data<<" ";
			}
		else
		{
			levelorder_print(root->right,dis-DL-2);
			}
			
		return DL+1;
		}
	int DR=print_at_distance_k(root->left,target,dis);//0
	
	if(DR!=-1)
	{
		if(DR+1==dis)
		{
			cout<<root->data<<" ";
			}
		else
		{
			levelorder_print(root->left,dis-DR-2);
			}
		return DR+1;
		}
		return -1;
	}
	
    
Node* LCA(Node *root,int a,int b)
{
    if(root == nullptr)
        return nullptr;
        
    if(root->data == a or root->data == b)
        return root;
        
    Node *left=LCA(root->left,a,b);
    Node* right=LCA(root->right,a,b);
    
    if(left!=nullptr and right!= nullptr)
        return root;
        
    if(left!=nullptr)
        return left;
    return right;
    }
    
class Pair
{
public:
    int branch_sum;
    int max_sum;
    
    Pair(){
        branch_sum=0;
        max_sum=0;        
    }
    };
    
Pair max_sum_path(Node *root)
{
    Pair p;
    
    //base case
    if(root==nullptr)
    return p;
    
    Pair left=max_sum_path(root->left);
    Pair right=max_sum_path(root->right);
    // for maxsum
    int op1=root->data;
    int op2=left.branch_sum+root->data;
    int op3=right.branch_sum+root->data;
    int op4=right.branch_sum+left.branch_sum+root->data;
    
    int  current_ans_thorugh_root=max(op1,max(op2,max(op3,op4)));
    
    //for max branch sum
    p.branch_sum=max(left.branch_sum,max(right.branch_sum,0))+root->data;
    p.max_sum=max(left.branch_sum,max(right.branch_sum,current_ans_thorugh_root));
    
    return p;
    }
    
int search(Node*root,int key,int level)
{
    if(root==nullptr)
        return -1;
    
    if(root->data==key)
        return level;
        
    int left=search(root->left,key,level+1);
    if(left!=-1)
        return left;
    return search(root->right,key,level+1);
    }
    
int smallest_distance_between_node(Node*root,int a,int b)
{
    Node *lca=LCA(root,a,b);
    
    int l1=search(lca,a,0);
    int l2=search(lca,b,0);
    
    return l1+l2;
    }
int main()
{
    int n;
	cin>>n;
    int pre[n];
	for(int i=0;i<n;i++)
	 cin>>pre[i];

    int in[n];
	for(int i=0;i<n;i++)
	 cin>>in[i];

Node *root=tree_from_trav(pre,in,0,n-1);
print(root);
	 return 0;
}


