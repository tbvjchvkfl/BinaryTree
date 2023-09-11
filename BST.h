#pragma once
#include <iostream>
#include <stack>
#include <set>
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

		Node* InsertNode(Node* parent, int value)
		{
			if (parent == nullptr)
			{
				return CreateNode(value);
			}

			if (value < parent->mData)
			{
				parent->mpLeft = InsertNode(parent->mpLeft, value);
			}
			else if (value > parent->mData)
			{
				parent->mpRight = InsertNode(parent->mpRight, value);
			}
			return parent;
		}

	public:
		void Visit(Node* node)
		{
			std::cout << node->mData << " ";
		}
		void InOrder(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}
			InOrder(node->mpLeft);
			Visit(node);
			InOrder(node->mpRight);
		}
		
	};
}

void BSTTest()
{
	using namespace mysearchtree;

	BinarySearchTree bst;

	auto proot = bst.InsertNode(nullptr, 8);
	bst.InsertNode(proot, 3);
	bst.InsertNode(proot, 10);
	bst.InsertNode(proot, 5);
	bst.InsertNode(proot, 1);
	bst.InsertNode(proot, 6);

	bst.InOrder(proot);
}

void PracticeSet()
{
	// 바이너리 서치 트리의 개념 set
	std::set<int>s;

	s.insert(8);
	s.insert(3);
	s.insert(5);
	s.insert(10);
	s.insert(6);
	s.insert(1);

	for (auto e : s)
	{
		std::cout << e << std::endl;
	}
}