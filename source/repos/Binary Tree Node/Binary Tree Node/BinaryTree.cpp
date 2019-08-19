#include "BinaryTree.h"

template <typename E>
int BinaryTree<E>::size() const
{
	return this->n; 
}

template <typename E>
bool BinaryTree<E>::empty() const
{
	return size() == 0;
}

template <typename E>
typename BinaryTree<E>::Position BinaryTree<E>::root()
{
	return typename BinaryTree<E>::Position(_root);
}

template <typename E>
NodeList<typename BinaryTree<E>::Position> BinaryTree<E>::Positions() 
{
	typename BinaryTree<E>::PositionList list;
	preorder(_root, list);
	return list;
}

template <typename E>
void BinaryTree<E>::addRoot()
{
	_root = new typename BinaryTree<E>::TreeNode;
	n = 1;
}

template <typename E>
void BinaryTree<E>::expandExternal(const Position& p)
{
	typename BinaryTree<E>::TreeNode* v = p.v;
	v->left = new typename BinaryTree<E>::TreeNode;
	v->left->par = v;
	v->right = new typename BinaryTree<E>::TreeNode;
	v->right->par = v;
	n += 2;
}

template <typename E>
typename BinaryTree<E>::Position BinaryTree<E>::removeAboveExternal(const Position& p)
{
	typename BinaryTree<E>::TreeNode* w = p.v;
	typename BinaryTree<E>::TreeNode* v = w->par;
	typename BinaryTree<E>::TreeNode* sib = (w == v->left ? v->right : v->left);
	if (v == _root) {
		_root = sib;
		sib->par = NULL;
	}
	else {
		typename BinaryTree<E>::TreeNode* gpar = v->par;
		if (v == gpar->left)
			gpar->left = sib;
		else
			gpar->right = sib;

		sib->par = gpar;
	}
	delete w;
	delete v;
	n -= 2;
	return Position(sib);
}

template <typename E>
void BinaryTree<E>::preorder(typename BinaryTree<E>::TreeNode* u, PositionList& pl)
{
	pl.insertBack(Position(u));
	if (u->left != NULL)
		for (typename BinaryTree<E>::PositionList::Iterator ii = pl.v->left.begin(); ii != pl.v->left.end(); ++ii)
			preorder(*ii, pl);
	if (u->right != NULL)
		for (typename BinaryTree<E>::PositionList::Iterator ii = pl.v->right.begin(); ii != pl.v->right.end(); ++ii)
			preorder(*ii, pl);
}

template <typename E>
E BinaryTree<E>::Position::operator*()
{
	return v->elt;
}

template <typename E>
typename BinaryTree<E>::Position BinaryTree<E>::Position::left() const
{
	return Position(v->left);
}

template <typename E>
typename BinaryTree<E>::Position BinaryTree<E>::Position::right() const
{
	return Position(v->right);
}

template <typename E>
typename BinaryTree<E>::Position BinaryTree<E>::Position::parent() const
{
	return Position(v->par);
}

template <typename E>
bool BinaryTree<E>::Position::isRoot() const
{
	return v->par == NULL;
}

template <typename E>
bool BinaryTree<E>::Position::isExternal() const
{
	return v->left == NULL && v->right == NULL;
}

template <typename E>
void BinaryTree<E>::insert(E e, Position p)
{
	typename BinaryTree<E>::TreeNode * u = new typename BinaryTree<E>::TreeNode;
	u->elt = e;
	if (empty())
		u->par = NULL;
	else
		u->par = p.v;
	if (!empty())
	{
		if (u->left != NULL)
			p.v->right = u;
		else
			p.v->left = u;
	}
	else
	{
		u->par = NULL;
		_root = u;
	}
	++n;
}