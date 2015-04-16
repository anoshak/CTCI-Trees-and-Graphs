/*
 * Zig_Zag_Print.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Anoshak
 */

#include "Trees.h"

void zigzag_print(node* root)
{
	stack<node*> mystack[2];

	if(root)
		mystack[0].push(root);

	while(!mystack[0].empty() || !mystack[1].empty())
	{
		while(!mystack[0].empty())
		{
			node* p = mystack[0].top();
			mystack[0].pop();
			cout<<p->data<<" ";
			if(p->left)
				mystack[1].push(p->left);
			if(p->right)
				mystack[1].push(p->right);
		}
		while(!mystack[1].empty())
		{
			node* p = mystack[1].top();
			mystack[1].pop();
			cout<<p->data<<" ";
			if(p->right)
				mystack[0].push(p->right);
			if(p->left)
				mystack[0].push(p->left);

		}

	}

}
