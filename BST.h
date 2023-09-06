#pragma once
#include <iostream>

namespace mysearchtree
{
	struct Node
	{
		int mData;
		Node* mpLeft;
		Node* mpRight;

		Node(int data = 0, Node* pleft = nullptr, Node* pright = nullptr)
		{
			mData = data;
			mpLeft = pleft;
			mpRight = pright;
		}
	};

	class BinarySearchTree
	{
	private:
		Node* mpRoot;

	public:
		BinarySearchTree()
		{
			mpRoot = CreateNode(0);
		}

		Node* CreateNode(int value, Node* pLeft = nullptr, Node* pRight = nullptr)
		{
			return new Node(value, pLeft, pRight);
		}

		Node* GetRoot()
		{
			return mpRoot;
		}

		Node* InsertLeft(Node* node, int value)
		{

		}

		Node* InsertRight(Node* node, int value)
		{
			
		}
	};
}