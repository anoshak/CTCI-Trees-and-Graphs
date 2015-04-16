/*
 * Q9.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Anoshak
 */

#include "trees.h"

void print_sum_paths2(node* root, int sum, vector<int> &myvector)
{
	if(root)
	{
		myvector.push_back(root->data);

		int t=0;
		for(int i=myvector.size() - 1; i>=0; i--)
		{
				t += myvector[i];
				if(t==sum)
				{
					for(int j=i ; j< myvector.size(); j++)
						cout<<myvector[j]<<" ";
					cout<<endl;
				}
		}

		if(root->left)
			print_sum_paths2(root->left,sum, myvector);
		if(root->right)
			print_sum_paths2(root->right,sum, myvector);

		myvector.pop_back();


	}

}

