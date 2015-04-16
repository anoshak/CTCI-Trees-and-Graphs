/*
 * Q5.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Anoshak
 */

#include "trees.h"

bool checkBST(node* root, int *prev_data)
{
	if(root==NULL)
		return 1;
	if(!checkBST(root->left, prev_data))
		return 0;

	if(root->data <= *prev_data)
		return 0;
	*prev_data = root->data;

	if(!checkBST(root->right, prev_data))
		return 0;

	return 1;

}

bool checkBST2(node* root, int min, int max)
{
	if(root==NULL)
		return 1;
	if(!checkBST2(root->left,min,root->data))
		return 0;

	if(root->data < min || root->data > max)
		return 0;

	if(!checkBST2(root->right,root->data,max))
		return 0;

	return 1;

}
/*
int main()
{
	node* root;
	int prev_data = INT_MIN;
	checkBST(root,&prev_data );
}
*/



