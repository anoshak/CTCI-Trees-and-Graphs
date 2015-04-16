/*
 * Q4.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Anoshak
 */

#include "Trees.h"

struct llnode
{
	node* nd;
	llnode* next;
};

void reverse(llnode **headptr)
{
	llnode* p = *headptr;
	llnode* prev = NULL;

	while(p)
	{
		llnode* ahead = p->next;
		p->next = prev;
		prev = p;
		p=ahead;
	}

	*headptr = prev;
}

vector<llnode*> lldepth(node* root)
{
	vector<llnode*> myvector;

	queue<node*> myqueue[2];
	int i = 0;
	node* p = root;
	llnode *head = NULL;

	if(p)
		myqueue[0].push(p);

	while(!myqueue[0].empty() || !myqueue[1].empty())
	{
		p=myqueue[i].front();
		myqueue[i].pop();
		llnode *temp = new llnode;
		temp->nd = p;
		if(head == NULL)
		{
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}

		if(p->left)
			myqueue[(i+1)%2].push(p->left);
		if(p->right)
			myqueue[(i+1)%2].push(p->right);

		if(myqueue[i].empty())
		{
			reverse(&head);
			myvector.push_back(head);
			head = NULL;
			i=(i+1)%2;
		}

	}

	return myvector;

}
