/*
 * Q8.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Anoshak
 */

#include "trees.h"

bool matchTree(node* bigtree, node* smalltree)
{
	if(smalltree==NULL && bigtree==NULL )
		return 1;
	if(bigtree == NULL || smalltree==NULL)
		return 0;
	if(bigtree->data != smalltree->data)
		return 0;
	return matchTree(bigtree->left, smalltree->left) && matchTree(bigtree->right, smalltree->right);
}

bool containsTree(node* bigtree, node* smalltree)
{
	if(smalltree==NULL)
		return 1;
	if(bigtree==NULL)
		return 0;
	if(bigtree->data==smalltree->data)
	{
		if(matchTree(bigtree,smalltree))
			return 1;
	}
	return containsTree(bigtree->left,smalltree) || containsTree(bigtree->right,smalltree);
}

