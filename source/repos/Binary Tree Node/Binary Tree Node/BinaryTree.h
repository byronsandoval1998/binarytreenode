#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "NodeList.cpp"
#include <cstdlib>

template <typename E>
class BinaryTree {
public:
	class BinaryTreeNode;
public:
	class Position
	{
	public:
		E operator*();
		Position left() const;
		Position right() const;
		Position parent() const;
		bool isRoot() const;
		bool isExternal() const;
		Position(typename BinaryTree<E>::TreeNode* _v = NULL) : v(_v) { }

		typename BinaryTree<E>::TreeNode* v;
		friend class NodeList<Position>;
	};

	typedef NodeList<Position> PositionList;

public:
	class TreeNode
	{
	public:
		E e;
		BinaryTreeNode *parent;
		typename BinaryTree<E>::Position child;
		friend class BinaryTree;
		friend class BinaryTree<E>::Position;
	protected:
		E elt;
		TreeNode* par;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : elt(), par(NULL), left(NULL), right(NULL) { }
	};
public:
	BinaryTree() : _root(NULL), n(0) { }
	int size() const;
	bool empty() const;

	Position root();
	PositionList Positions();

	void addRoot();
	void expandExternal(const Position& p);
	Position removeAboveExternal(const Position& p);

	void insert(E e, Position p);
	void preorder(typename BinaryTree<E>::TreeNode* u, PositionList &pre_order);
	private:
		typename BinaryTree<E>::TreeNode* _root;
		int n;
	friend class Position;
};

#endif