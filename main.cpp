// #include "BinaryTree.h"
// 
//using namespace mytree;


#include "BST.h"
using namespace mysearchtree;

void BT_Test()
{
	//BinaryTree bt;
	//auto pRoot = bt.GetRoot();
	//pRoot->mData = 1;

	//auto pNode = bt.InsertLeft(pRoot, 2);
	//bt.InsertLeft(pNode, 4);
	//bt.InsertRight(pNode, 5);

	//pNode = bt.InsertRight(pRoot, 3);
	//bt.InsertLeft(pNode, 6);
	//bt.InsertRight(pNode, 7);





	//// 순회 방식
	//// BFS ( Breadth First Seartch )
	//bt.BreadthFirstSearch();
	//std::cout << std::endl;
	//// DFS ( Depth First Search )
	//bt.DepthFirstSearch();
	//std::cout << std::endl;
	//bt.DFSRecursive(pRoot);
	//std::cout << std::endl;

	//bt.SumPreOrder(pRoot);
}


int main()
{
	BinarySearchTree bst;

	auto pRoot = bst.GetRoot();
	pRoot->mData = 1;
	
	auto pNode = bst.InsertNode(pRoot, 2);

	bst.InsertNode(pNode, 3);
	bst.InsertNode(pNode, 4);
	pNode = bst.InsertNode(pNode, 5);
	bst.InsertNode(pNode, 6);
	bst.InsertNode(pNode, 7);

	bst.DFS(pRoot);
	
	
}