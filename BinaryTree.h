#pragma once
#include<iostream>
#include <queue>
#include <stack>

namespace mytree
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

	class BinaryTree
	{
	private:
		Node* mpRoot;

	public:
		BinaryTree()
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
			parent->mpLeft = CreateNode(value);
			return parent->mpLeft;
		}
		Node* InsertRight(Node* parent, int value)
		{
			parent->mpRight = CreateNode(value);
			return parent->mpRight;
		}

	public:
		void Visit(Node* node) { std::cout << node->mData; }
		int Sum(Node* node)
		{
			int a{};
			a += node->mData;
			return a;
		}
		void BreadthFirstSearch()
		{
			std::queue<Node*> q;
			q.push(mpRoot);
			while (!q.empty())
			{
				auto node = q.front();
				Visit(node);
				q.pop();

				if (node->mpLeft)
				{
					q.push(node->mpLeft);
				}
				if (node->mpRight != nullptr)
				{
					q.push(node->mpRight);
				}
			}
		}

		// �ù�... �̷��� ������ ����� �־���....
		void DepthFirstSearch()
		{
			std::stack<Node*> s;
			s.push(mpRoot);
			
			while (!s.empty())
			{
				auto node = s.top();
				Visit(node);
				s.pop();

				if (node->mpRight)
				{
					s.push(node->mpRight);
				}
				if (node->mpLeft)
				{
					s.push(node->mpLeft);
				}
			}

		}

		void DFSRecursive(Node* node)
		{
			if (!node)
			{
				return;
			}

			Visit(node);

			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
		}


		// Visit�� �����ϴ��Ŀ� ���� ��� ����
		// 
		//preorder
		void PreOrder(Node* node)
		{
			if (!node)
			{
				return;
			}

			Visit(node);

			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
		}

		// inorder
		void InOrder(Node* node)
		{
			if (!node)
			{
				return;
			}

			
			DFSRecursive(node->mpLeft);
			Visit(node);
			DFSRecursive(node->mpRight);
		}

		// postorder
		void PostOrder(Node* node)
		{
			if (!node)
			{
				return;
			}

			

			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
			Visit(node);
		}

		void SumPreOrder(Node* node)
		{

			if (!node)
			{
				return;
			}
			Sum(node);
			SumPreOrder(node->mpLeft);
			SumPreOrder(node->mpRight);
		}

		int SumT(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}

			return SumT(node->mpLeft) + node->mData + SumT(node->mpRight);
		}
		bool SearchTarget(Node* node, int value)
		{
			if (!node)
			{
				return false;
			}
						
			if (node->mData == value || SearchTarget(node->mpLeft, value) || SearchTarget(node->mpRight, value))
			{
				return true;
			}
		}

		bool SearchT(Node* node, int value)
		{
			if (!node) return false;

			return node->mData == value || SearchT(node->mpLeft, value) || SearchT(node->mpRight, value);
		}

		// Ʈ���� ���̸� ���ϴ� �Լ��� ����� �� ��.
		int TreeDepth(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			
			TreeDepth(node->mpLeft);

			int a{};
			while (node->mpLeft != nullptr)
			{
				a++;
			}
			return a;
		}

	};
}