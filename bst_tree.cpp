#include <iostream>

using namespace std;

struct bst
{
	int data;
	bst* left;
	bst* right;
};


bst* createnode(int data)
{
	bst* newnode=new bst();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

bst* insert(bst* root, int data)
{
	if (root==NULL)
	{
		root=createnode(data);
	}
	else if (data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
}

void inorder(bst* root)
{
	if (root==NULL)
	{
		return ;
	}
	else
	{
		inorder(root->left);
	    cout<<root->data<<",";
	    inorder(root->right);

	}
	

}

bool check(bst* root, int data)
{
	if (root==NULL)
	{
		return false;
	}
	else if (data==root->data)
	{
		return true;
	}
	else if (data<=root->data)
	{
		check(root->left,data);
	}
	else
	{
		check(root->right,data);
	}
}

int main()
{
	bst* root=NULL;
	root=insert(root,10);
	root=insert(root,15);
	root=insert(root,3);
	root=insert(root,8);
	root=insert(root,7);
	root=insert(root,2);
	root=insert(root,5);
	root=insert(root,20);
	if (check(root,3))
	{
		cout<<"we have found"<<endl;

	}
	else
	{
		cout<<"we have not found"<<endl;
	}
	inorder(root);
	return 0;


}