/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void append(int *arr, int *index, int value){
	arr[*index] = value;
	(*index)++;
}
void performInOrder(struct node *root, int *arr, int *index){
	if (root == NULL)
		return;
	
	performInOrder(root->left, arr,index);
	append(arr, index, root->data);
	performInOrder(root->right, arr,index);
}

void performPreOrder(struct node *root, int *arr, int *index){
	if (root == NULL)
		return;
	append(arr, index, root->data);
	performInOrder(root->left, arr,index);
	performInOrder(root->right, arr,index);
}
void performPostOrder(struct node *root, int *arr, int *index){
	if (root == NULL)
		return;
	
	performInOrder(root->left, arr,index);
	performInOrder(root->right, arr,index);
	append(arr, index, root->data);
}
void inorder(struct node *root, int *arr){
	if (root && arr){
		int index = 0;
		performInOrder(root, arr, &index);
	}
}
void preorder(struct node *root, int *arr){
	if (root && arr){
		int index = 0;
		performPreOrder(root, arr, &index);
	}
}
void postorder(struct node *root, int *arr){
	if (root && arr){
		int index = 0;
		performPostOrder(root, arr,&index);
	}
}

