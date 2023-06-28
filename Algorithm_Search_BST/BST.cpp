#pragma once
#include "BST.h"

extern Node *head;

Node* Tree_Minimum(Node* node);
Node* BST_Successor(Node* node);


Node* BST_SearchNode(Node* x, int target)
{
	if (x == NULL || target == x->data)
		return x;
	
	if (target < x->data)
		BST_SearchNode(x->left, target);
	else
		BST_SearchNode(x->right, target);
}

void BST_InsertNode(Node* tree, Node* node)
{
	Node *y = NULL;
	Node *x = tree;

	while (x != NULL) {
		y = x;

		if (node->data < x->data) 
			x = x->left;
		else 
			x = x->right;
	}

	if (y == NULL) { //tree가 비어있는 경우
		head = node;
		return;
	}
	else if (y->data > node->data) {
		y->left = node;
	}
	else {
		y->right = node;
	}
	node->p = y;
}

Node* BST_DeleteNode(Node* tree, Node* node) {
	Node* x;
	Node* y; //실제로 지워지는 노드를 가리킴

	if (node->left == NULL && node->right == NULL) { //지우려는 노드 자식 없음
		y = node;

		if (y->p == NULL) { //y가 루트일 때
			head = NULL;
		}

		if (y == y->p->left)
			y->p->left = NULL;
		else
			y->p->right = NULL;

		return y;
	}
	else if (node->left == NULL || node->right == NULL) { //지우려는 노드가 자식 하나 가짐
		y = node;

		if (y->left != NULL) //y가 왼쪽 자식 가질 때
			x = y->left;
		else //y가 오른쪽 자식 가질 때
			x = y->right;

		if (y->p == NULL) { //y가 루트일 때
			head = x;
		}

		x->p = y->p;

		if (y == y->p->left)
			y->p->left = x;
		else
			y->p->right = x;

		return y;
	}
	else { //지우려는 노드가 자식 2개
		y = BST_Successor(node);

		node->data = y->data;

		if (y == y->p->left) { //successor y가 왼쪽자식노드일때
			y->p->left = y->right;

			if (y->right != NULL) //y가 오른쪽자식 있을 때
				y->right->p = y->p;
		}
		else //y가 오른쪽 노드일 땐 자식이 있을 수 없음
			y->p->right = NULL;

		return y;
	}
}

Node* BST_Successor(Node* node) {
	Node* y;

	if (node->right != NULL) //node가 오른쪽 부트리가 있다면
		return Tree_Minimum(node->right);

	y = node->p;

	while (y != NULL && node == y->right) {
		node = y;
		y = y->p;
	}

	return y;
}

Node* Tree_Minimum(Node* node) { //Tree 내 최솟값 찾기
	while (node->left != NULL) 
		node = node->left;
		
	return node;
}

void BST_PreOrder(Node* tree) { //선순위 순회
	if (tree == NULL)
		return;

	std::cout << tree->data << " ";
	BST_PreOrder(tree->left);
	BST_PreOrder(tree->right);
}

void BST_InOrder(Node* tree) { //중위 순회
	if (tree == NULL)
		return;

	BST_InOrder(tree->left);
	std::cout << tree->data << " ";
	BST_InOrder(tree->right);
}

void BST_PostOrder(Node* tree){ //후순위 순회
	if (tree == NULL)
		return;

	BST_PostOrder(tree->left);
	BST_PostOrder(tree->right);
	std::cout << tree->data << " ";
}