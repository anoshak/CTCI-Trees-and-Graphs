/*
 * Trees.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Anoshak
 */

#include "Trees.h"

bool iterative_search(node* root, int value, node** pptr, node** prevptr)
{
	*pptr = root;
	*prevptr = NULL;
	while(*pptr)
	{
		if((*pptr)->data==value)
			return 1;
		else
		{
			*prevptr=*pptr;
			if(value < (*pptr)->data)
				*pptr=(*pptr)->left;
			else *pptr=(*pptr)->right;
		}
	}
	return 0;
}

bool iterative_add(node** rootptr, int value)
{
	node *p,*prev;
	if(iterative_search(*rootptr,value,&p,&prev))
		return 0;
	else
	{
		p = new node;
		if(p==NULL)
			return 0;
		p->data = value;
		p->left=p->right=NULL;
		if(prev==NULL)
			*rootptr = p;
		else if(value < prev->data)
			prev->left=p;
		else
			prev->right=p;
		return 1;

	}
}

bool iterative_delete(node** rootptr, int value)
{
	node*p,*prev;
	if(!iterative_search(*rootptr, value,&p,&prev))
		return 0;
	else
	{
		if(p->left==NULL)
		{
			if(prev==NULL)
				*rootptr = p->right;
			else if(prev->left==p)
				prev->left = p->right;
			else prev->right = p->right;
		}
		else if(p->right==NULL)
		{
			if(prev==NULL)
				*rootptr=p->left;
			else if(prev->left==p)
				prev->left = p->left;
			else prev->right = p->right;
		}
		else
		{
			node *temp = p->right;
			while(temp->left)
				temp=temp->left;
			temp->left = p->left;
			if(prev==NULL)
				*rootptr = p->right;
			else if(prev->left == p)
				prev->left = p->right;
			else prev->right = p->right;
		}
		free(p);
		return 1;
	}

}

bool recursive_search(node *root, int value)
{
	if(root==NULL)
		return 0;
	if(root->data == value)
		return 1;
	if(value < root->data)
		return recursive_search(root->left, value);
	else return recursive_search(root->right,value);

}

bool recursive_add(node** rootptr, int value)
{
	node * p = *rootptr;
	if(p==NULL)
	{
		node* newnode = new node;
		newnode->data = value;
		newnode->left = newnode->right = NULL;
		*rootptr = newnode;
		return 1;
	}
	else if(p->data==value)
		return 0;
	else if(value < p->data)
		return recursive_add(&p->left, value);
	else return recursive_add(&p->right, value);

}

bool recursive_delete(node** rootptr, int value)
{
	node* p = *rootptr;
	if(p==NULL)
		return 0;
	if(value < p->data)
		return recursive_delete(&p->left, value);
	else if(value > p->data)
		return recursive_delete(&p->right, value);
	else
	{
		if(p->left == NULL)
			*rootptr = p->right;
		else if(p->right == NULL)
			*rootptr = p->left;
		else
		{
			node* temp = p->right;
			while(temp->left)
				temp=temp->left;
			temp->left=p->left;
			*rootptr = p->right;
		}
		free(p);
		return 1;
	}
}

void inorder(node* root)
{
	if(root)
	{
		static int i = root->data;
		if(root->left)
		{
			inorder(root->left);
			cout<<",";
		}

		cout<<root->data<<" ";

		if(root->right)
		{
			cout<<",";
			inorder(root->right);
		}

		if(i==root->data)
			cout<<"."<<endl;

	}
}

void inorder_iterative(node* root)
{
	stack<node*> mystack;
	while(1)
	{
		while(root)
		{
			mystack.push(root);
			root=root->left;
		}

		if(mystack.size()==0)
			break;
		root = mystack.top();
		mystack.pop();
		cout<<root->data<<" ";

		root=root->right;
	}
	cout<<endl;
}
void preorder(node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);

	}
}

void preorder_iterative(node* root)
{
	stack<node*> mystack;

	while(1)
	{
		while(root)
		{
			cout<<root->data<<" ";
			mystack.push(root);
			root=root->left;
		}
		if(mystack.empty())
			break;
		root=mystack.top();
		mystack.pop();

		root = root->right;
	}
}

void postorder(node* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";

	}
}

struct stackelem
	{
		node* p;
		bool popped_once;
	};

void postorder_iterative(node* root)
{

	stackelem s;
	stack<stackelem> mystack;

	while(1)
	{
		while(root)
		{
			s.p=root;
			s.popped_once=0;
			mystack.push(s);
			root=root->left;
		}

		if(mystack.empty())
			break;
		s = mystack.top();
		mystack.pop();
		root=s.p;
		if(s.popped_once == 0)
		{
			s.popped_once=1;
			mystack.push(s);
			root = root->right;
		}
		else
		{
			cout<<root->data<<" ";
			root=NULL;

		}
	}
}

void levelorder(node* root)
{
	queue<node*> myqueue;
	node* p = root;

	if(p)
		myqueue.push(p);

	while(!myqueue.empty())
	{
		p=myqueue.front();
		myqueue.pop();
		cout<<p->data<<" ";
		if(p->left)
			myqueue.push(p->left);
		if(p->right)
			myqueue.push(p->right);
	}
	cout<<endl;
}

struct qelement
{
	node * nd;
	int level;
};
void levelorder2(node* root)
{
	//print each level on new line

	qelement qitem;
	node* p=root;
	queue<qelement> myqueue;
	int currlevel = 0;

	if(p)
	{
		qitem.nd=p;
		qitem.level=0;
		myqueue.push(qitem);
	}

	while(!myqueue.empty())
	{
		qitem = myqueue.front();
		myqueue.pop();
		if(qitem.level > currlevel)
		{
			cout<<endl;
			currlevel++;
		}
		p=qitem.nd;
		int level = qitem.level;
		cout<<p->data<<" ";
		if(p->left)
		{
			 qitem.nd = p->left;
			 qitem.level = level+1;
			 myqueue.push(qitem);

		}
		if(p->right)
		{
			 qitem.nd = p->right;
			 qitem.level = level+1;
			 myqueue.push(qitem);

		}
	}
	cout<<endl;

}

void levelorder3(node* root)
{
	//print each level on new line - using two queues
	queue<node*> myqueue[2];
	node* p = root;
    int i = 0;

    if(p)
    	myqueue[0].push(p);

    while(!myqueue[0].empty() || !myqueue[1].empty())
    {
    	p=myqueue[i].front();
    	myqueue[i].pop();
    	cout<<p->data<<" ";

    	if(p->left)
    		myqueue[(i+1)%2].push(p->left);
    	if(p->right)
    		myqueue[(i+1)%2].push(p->right);

    	if(myqueue[i].empty())
    	{
    		i=(i+1)%2;
    		cout<<endl;
    	}

    }
    cout<<endl;
}

int height(node* root)
{
	if(root==NULL)
		return 0;
	else
	{
		int h1 = height(root->left);
		int h2 = height(root->right);
		return (h1>h2 ? h1+1 : h2+1);

	}
}

bool isBalanced(node* root, int* height)
{
	if(root==NULL)
	{
		*height = 0;
		return 1;
	}
	int lh,rh;
	bool lb,rb;
	lb = isBalanced(root->left, &lh);
	rb = isBalanced(root->right,&rh);

	*height = lh>rh ? lh+1 : rh+1;

	if(lb && rb && abs(lh-rh)<2)
		return 1;
	else return 0;
}

node* inorder_successor(node* root, int value)
{
	node* left = NULL;
	while(root)
	{
	if(root->data == value)
	{
		if(root->right)
		{
			root=root->right;
			while(root->left)
				root=root->left;
			return root;
		}
		else return left;
	}
	else if(value < root->data)
	{
		left = root;
		root=root->left;
	}
	else root=root->right;
	}
	return NULL;
}



