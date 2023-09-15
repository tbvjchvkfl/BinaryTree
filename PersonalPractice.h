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

	public:
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

		bool Find(Node* node, int data)
		{
			if (!node)
			{
				return false;
			}

			if (node->mData == data || Find(node->mLeft, data) || Find(node->mRight, data))
			{
				return true;
			}
		}

		void FindFunc_t_void(Node* node, int data)
		{
			if (node != nullptr)
			{
				return;
			}
			if (node->mData == data)
			{
				std::cout << "검색 성공!!" << std::endl;
				return;
			}
			else if (Find(node->mLeft, data))
			{

			}
		}

	};

	class BST : BT
	{
		Node* InsertNode(Node* node, int value)
		{
			if (node == nullptr)
			{
				return CreateNode(value);
			}

			if (value < node->mData)
			{
				node->mLeft = InsertNode(node->mLeft, value);
			}
			else if (value > node->mData)
			{
				node->mRight = InsertNode(node->mRight, value);
			}
			return node;
		}

		void InOrderSearch(Node* node)
		{
			if (!node)
			{
				return;
			}

			InOrderSearch(node->mLeft);
			Visit(node);
			InOrderSearch(node->mRight);
		}
	};



	void Test_Binary()
	{
		
	}
}