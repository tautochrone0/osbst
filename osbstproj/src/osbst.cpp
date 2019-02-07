/**
 *
 * @file: OSBST.cpp
 * @author: Daniel Angelov <tautochrone4@gmail.com>
 *
 * @brief: Implementation of Order Statistics Tree (variant of Binary Search Tree)
 *		  Ref: https://en.wikipedia.org/wiki/Order_statistic_tree
 *
 *		  Supported operations:
 *
 *			(1) Insertion. Operation complexity O(h)
 *			(2) Median value retrieval. Operation complexity O(h)
 *
 *			where h = height of the BST.
 *
 *	@note For achieving worst-case complexity O(logn) for operations (1) and (2), a self-banacing tree can be used insted of ordinary BST.
 */

#include "osbst.h"
#include <iostream>

 //===============================================
 // Public functions.
 //===============================================
OSBST::OSBST()
	: root(nullptr)
{/* ... */
}

OSBST::~OSBST()
{
	freeAllNodes(root);
}

/**
 * @breif Inserts an integer x in the tree.
 *
 * @param[in] integer.
 * @retval none
 */
void OSBST::Insert(int x)
{
	if (root == nullptr)
	{
		root = createNode(x);
	}
	else
	{
		insertNode(root, x);
	}
}

/**
 * @breif Finds the median value of the elements of the tree.
 *
 * @retval the median value.
 */
float OSBST::MedianValue()
{
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		int numNodes = sizeofNode(root);
		if ((numNodes % 2) == 0)
		{
			int l = numNodes / 2;
			return (selectNode(root, l - 1) + selectNode(root, l)) / 2.0f;
		}
		else
		{
			int l = (numNodes + 1) / 2;
			return selectNode(root, l - 1);
		}
	}
}


//===============================================
// Internal helper functions.
//===============================================
void OSBST::insertNode(OSBST::Node* node, int x)
{
	if (x < node->data)
	{
		if (node->left == nullptr)
		{
			node->left = createNode(x);
		}
		else
		{
			insertNode(node->left, x);
		}
	}
	else
	{
		if (node->right == nullptr)
		{
			node->right = createNode(x);
		}
		else
		{
			insertNode(node->right, x);
		}
	}
	node->size += 1;
}

void OSBST::freeAllNodes(OSBST::Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		freeAllNodes(node->left);
		freeAllNodes(node->right);
		delete node;
	}
}

OSBST::Node* OSBST::createNode(int x)
{
	Node* node = new Node;
	node->left = node->right = nullptr;
	node->data = x;
	node->size = 1;
	return node;
}

int OSBST::selectNode(OSBST::Node* node, int i)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		int l = sizeofNode(node->left);

		if (i == l)
		{
			return node->data;
		}
		else
			if (i < l)
			{
				return selectNode(node->left, i);
			}
			else
			{
				return selectNode(node->right, i - (l + 1));
			}
	}
}

int OSBST::sizeofNode(OSBST::Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return (node->left == nullptr ? 0 : node->left->size) + (node->right == nullptr ? 0 : node->right->size) + 1;
}