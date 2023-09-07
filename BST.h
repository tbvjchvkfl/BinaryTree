#pragma once
#include <iostream>
#include <stack>
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

		Node* InsertNode(Node* node, int value)
		{
			if (value <= mpRoot->mData)
			{
				node->mpLeft = CreateNode(value);
				return node->mpLeft;
			}
			if (value > mpRoot->mData)
			{
				node->mpRight = CreateNode(value);
				return node->mpRight;
			}
		}

		void Travers(Node* node)
		{
			std::cout << node->mData;
		}

		void DFS(Node* node)
		{
			std::stack<Node*> s;
			if (node == nullptr)
			{
				return;
			}

			Travers(node);

			DFS(node->mpLeft);
			DFS(node->mpRight);
		}
	};
}