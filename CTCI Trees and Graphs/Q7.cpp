/*
 * Q7.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Anoshak
 */

#include "trees.h"

node* lca(node* root, node* a, node* b)
{
	if(root == NULL)
		return NULL;

	if(root == a || root ==b)
		return root;

	node* left = lca(root->left,a,b);
	node* right = lca(root->right,a,b);

	if(left && right)
		return root;
	else if(left)
		return left;
	else return right;

}



