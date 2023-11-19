#pragma once
#include<utility>
#include<assert.h>
using namespace std;
enum Color
{
	RED,
	BLACK,
};


template<class value>
struct RBTreeNode
{
	RBTreeNode<value>* _left;
	RBTreeNode<value>* _right;
	RBTreeNode<value>* _parent;
	value _value;
	Color _col;

	RBTreeNode(const value& v)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(v)
		, _col(RED)
	{}
};

template<class value, class ref, class ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<value> Node;
	typedef __RBTreeIterator<value, ref, ptr> self;
	typedef __RBTreeIterator<value, value&, value*> iterator;
public:
	__RBTreeIterator(Node* node)
		:_node(node)
	{}
	__RBTreeIterator(const iterator& t)
	{
		_node = t._node;
	}

	ref operator*()
	{
		return _node->_value;
	}
	ptr operator->()
	{
		return &(_node->_value);
	}
	self operator++()
	{
		if (_node->_right)//�����������Ϊ�գ���++�Ľ��Ϊ������������ڵ�
		{
			Node* cur = _node->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	bool operator!=(const self& self)
	{
		return _node != self._node;
	}
//private:
	Node* _node;
};

template<class key, class value, class keyOfValue>
class RBTree
{
	typedef RBTreeNode<value> Node;
public:
	typedef __RBTreeIterator<value, value&, value*> iterator;
	typedef __RBTreeIterator<value, const value&, const value*> const_iterator;

	iterator begin()
	{
		if (_root == nullptr)
		{
			return iterator(nullptr);
		}

		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
		
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	const_iterator begin()const
	{
		if (_root == nullptr)
		{
			return const_iterator(nullptr);
		}

		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);

	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
	~RBTree()
	{
		_destroy(_root);
		_root = nullptr;
	}
	pair<iterator, bool> insert(const value& kv)
	{
		keyOfValue key_of_value;
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			//if (cur->_kv.first < kv.first)
			if (key_of_value(cur->_value) < key_of_value(kv))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key_of_value(cur->_value) > key_of_value(kv))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}
		cur = new Node(kv);
		cur->_col = RED;
		//if (parent->_kv.first < kv.first)
		if (key_of_value(parent->_value) < key_of_value(kv))
		{
			parent->_right = cur;
		}
		else if (key_of_value(parent->_value) > key_of_value(kv))
		{
			parent->_left = cur;
		}
		else
		{
			assert(false);
		}
		cur->_parent = parent;
		Node* newnode = cur;//��������²���Ľڵ㣬������󷵻�;

		//���濪ʼ������ɫ����ת
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			Node* uncle = grandfather->_right;
			if (parent == grandfather->_right)
			{
				uncle = grandfather->_left;
			}

			if (parent->_col == RED && grandfather->_col == BLACK && (uncle) && (uncle->_col == RED))//����Ҫ��ת�����
			{
				parent->_col = uncle->_col = BLACK;
				grandfather->_col = RED;
				cur = grandfather;
				parent = grandfather->_parent;
			}
			else if (parent->_col == RED && grandfather->_col == BLACK && ((uncle == nullptr) || (uncle->_col == BLACK)))//��Ҫ��ת�����
			{
				if (cur == parent->_left && parent == grandfather->_left)//ֻ��Ҫ�ҵ���
				{
					rotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
				else if (cur == parent->_right && parent == grandfather->_right)//ֻ��Ҫ����
				{
					rotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
				else if (cur == parent->_right && parent == grandfather->_left)//��Ҫ����˫��
				{
					rotateL(parent);
					rotateR(grandfather);
					cur->_col = BLACK;
					grandfather->_col = RED;
				}
				else if (cur == parent->_left && parent == grandfather->_right)//��Ҫ����˫��
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

				break;//�����������,��ת��parent�����С�����ĸ�(��ȻҲ����Ϊ_root)����parent->_col=BLACK��һ����������������ֱ��break����ѭ����return true;
			}
			else
			{
				assert(false);
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
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
	//��ת����
		//�ҵ���
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
			if (pparent->_right == parent)
			{
				pparent->_right = subL;
			}
			else if (pparent->_left == parent)
			{
				pparent->_left = subL;
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
	//����
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
			subR->_parent = pparent;
			if (pparent->_right == parent)
			{
				pparent->_right = subR;
			}
			else if (pparent->_left == parent)
			{
				pparent->_left = subR;
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