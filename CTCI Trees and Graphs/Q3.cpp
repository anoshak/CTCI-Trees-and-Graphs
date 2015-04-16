/*
 * Q3.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Anoshak
 */

#include "Trees.h"

node* minimalBST(int* arr, int low, int high)
{
	if(high<low)
		return NULL;
	int mid = (low + high)/2;
	node *p = new node;
	p->data = arr[mid];
	p->left = minimalBST(arr,low, mid-1);
	p->right = minimalBST(arr, mid+1,high);
	return p;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	node* root = minimalBST(arr,0,9);
	inorder(root);
	return 0;
}

