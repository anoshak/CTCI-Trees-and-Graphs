/*
 * Trees.h
 *
 *  Created on: Feb 26, 2015
 *      Author: Anoshak
 */

#ifndef TREES_H_
#define TREES_H_

#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<limits.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

bool iterative_search(node* root, int value, node** pptr, node** prevptr);
bool iterative_add(node** rootptr, int value);
bool iterative_delete(node** rootptr, int value);
bool recursive_search(node *root, int value);
bool recursive_add(node** rootptr, int value);
bool recursive_delete(node** rootptr, int value);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
void inorder_iterative(node* root);
void preorder_iterative(node* root);
void postorder_iterative(node* root);
void levelorder(node* root);
void levelorder2(node* root);
void levelorder3(node* root);
int height(node* root);
bool isBalanced(node* root, int* height);
node* inorder_successor(node* root, int value);




#endif /* TREES_H_ */
