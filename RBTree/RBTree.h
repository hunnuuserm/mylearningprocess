#pragma once
#include<utility>
#include<assert.h>
using namespace std;
enum Color
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Color _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};


template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	~RBTree()
	{
		_destroy(_root);
		_root = nullptr;
	}
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first = kv.first)
			{
				parent = cur;
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			assert(false);
		}
		cur->_parent = parent;

		//下面开始调整颜色，旋转
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			Node* uncle = grandfather->_right;
			if (parent == grandfather->_right)
			{
				uncle = grandfather->_left;
			}

			if (parent->_col == RED && grandfather->_col == BLACK && (uncle) && (uncle->_col == RED))//不需要旋转的情况
			{
				parent->_col = uncle->_col = BLACK;
				grandfather->_col = RED;
				cur = grandfather;
				parent = grandfather->_parent;
			}
			else if (parent->_col == RED && grandfather->_col == BLACK && ((uncle == nullptr) || (uncle->_col == BLACK)))//需要旋转的情况
			{
				if (cur == parent->_left && parent == grandfather->_left)//只需要右单旋
				{
					rotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
				else if (cur == parent->_right && parent == grandfather->_right)//只需要左单旋
				{
					rotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
				else if (cur == parent->_right && parent == grandfather->_left)//需要左右双旋
				{
					rotateL(parent);
					rotateR(grandfather);
					cur->_col = BLACK;
					grandfather->_col = RED;
				}
				else if (cur == parent->_left && parent == grandfather->_right)//需要右左双旋
				{
					rotateR(parent);
					rotateL(grandfather);
					cur->_col = BLACK;
					grandfather->_col = RED;
				}
				else
				{
					assert(false);
				}

				break;//不论哪种情况,旋转后parent是这个小子树的根(当然也可能为_root)，且parent->_col=BLACK，一定满足条件，这里直接break跳出循环后return true;
			}
			else
			{
				assert(false);
			}
		}
		_root->_col = BLACK;
		return true;
	}
	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}
	bool isBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		if (_root->_col == RED)
		{
			return false;
		}

		Node* cur = _root;
		int blackCount = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				blackCount++;
			}
			cur = cur->_left;
		}

		return _isBalance(_root, blackCount, 0);
	}
private:
	void _destroy(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_destroy(root->_left);
		_destroy(root->_right);
		delete root;
	}
	void _inOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inOrder(root->_left);
		cout << "(" << root->_kv.first << "," << root->_kv.second << ")->";
		_inOrder(root->_right);
	}
	bool _isBalance(Node* root, int blackCount, int count)
	{
		if (root == nullptr)
		{
			if (count != blackCount)
			{
				return false;
			}
			return true;
		}
		

		if (root->_col == RED)
		{
			if (root->_parent->_col != BLACK)
			{
				return false;
			}
		}
		else
		{
			count++;
		}

		return _isBalance(root->_left, blackCount, count)
			&& _isBalance(root->_right, blackCount, count);
	}
	//旋转函数
		//右单旋
	void rotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* pparent = parent->_parent;
		parent->_left = subL->_right;
		if (subL->_right)
		{
			subL->_right->_parent = parent;
		}
		subL->_right = parent;
		parent->_parent = subL;
		if (pparent)
		{
			subL->_parent = pparent;
			if (pparent->_kv.first < subL->_kv.first)
			{
				pparent->_right = subL;
				subL->_parent = pparent;
			}
			else if (pparent->_kv.first > subL->_kv.first)
			{
				pparent->_left = subL;
				subL->_parent = pparent;
			}
			else
			{
				assert(false);
			}
		}
		else
		{
			subL->_parent = nullptr;
			_root = subL;
		}
	}
	//左单旋
	void rotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* pparent = parent->_parent;
		parent->_right = subR->_left;
		if (subR->_left)
		{
			subR->_left->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;
		if (pparent)
		{
			if (pparent->_kv.first < subR->_kv.first)
			{
				pparent->_right = subR;
				subR->_parent = pparent;
			}
			else if (pparent->_kv.first > subR->_kv.first)
			{
				pparent->_left = subR;
				subR->_parent = pparent;
			}
			else
			{
				assert(false);
			}
		}
		else
		{
			subR->_parent = nullptr;
			_root = subR;
		}
	}
private:
	Node* _root = nullptr;
};