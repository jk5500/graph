#include <iostream>
#include <queue>

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
	else if( data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}
void inorder(bst* root)
{
	if (root==NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		cout<<root->data<<",";
		inorder(root->right);
	}
}

void levelorder(bst* root)
{
	if (root==NULL)
	{
		return;
	}
	else
	{
		queue<bst*> queue;
		queue.push(root);

		while (!queue.empty())
		{
			bst* current=queue.front();
			cout<<current->data<<",";
			if (current->left!=NULL)
			{
				queue.push(current->left);
			}
			if (current->right!=NULL)
			{
				queue.push(current->right);
			}
			queue.pop();
		}

	}
}
int main()
{
	bst* root=NULL;
	root=insert(root,2);
	root=insert(root,4);
	root=insert(root,3);
	root=insert(root,1);
	root=insert(root,5);
	root=insert(root,9);
	root=insert(root,8);

	cout<<"in order traversal  ";

	inorder(root);
	cout<<endl;

	cout<<"level order traversal  ";

	levelorder(root);
	cout<<endl;




}