#pragma once
#include <iostream>
#include <stack>

namespace PersonalPractice
{

	struct Node
	{
		int mData{};
		Node* mLeft{};
		Node* mRight{};
		Node(int data = 0, Node* left = nullptr, Node* right = nullptr)
		{
			mData = data;
			mLeft = left;
			mRight = right;
		}
	};

	class BT
	{
	private:
		Node* mpRoot;

	public:
		BT()
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

		Node* InsertLeft(Node* parent, int value)
		{
			parent->mLeft = CreateNode(value);
			return parent->mLeft;
		}
		Node* InsertRight(Node* parent, int value)
		{
			parent->mRight = CreateNode(value);
			return parent->mRight;
		}

		void Visit(Node* node)
		{
			std::cout << node->mData << ", ";
		}

		void DFS(Node* node)
		{
			if (node != nullptr)
			{
				return;
			}
			
			Visit(node);
			DFS(node->mLeft);
			DFS(node->mRight);
		}


	};

	class BST : BT
	{
		Node* InsertNode(Node* parent, int value)
		{
			if (parent == nullptr)
			{
				return CreateNode(value);
			}

			if (value < parent->mData)
			{
				parent->mLeft = InsertNode(parent->mLeft, value);
			}
			else if (value > parent->mData)
			{
				parent->mRight = InsertNode(parent->mRight, value);
			}
			return parent;
		}
	};
}