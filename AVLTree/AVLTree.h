#pragma once
#include<utility>
#include<assert.h>
//using namespace std;

namespace m
{
	template<class K, class V>
	struct AVLTreeNode
	{
	/*public:*/
		AVLTreeNode(pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _bf(0)
		{}
	/*private:*/

		AVLTreeNode* _left;
		AVLTreeNode* _right;
		AVLTreeNode* _parent;
		pair<K, V> _kv;
		int _bf;
	};


	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		void inOrder()
		{
			_inOrder(_root);
			cout << endl;
		}
		bool isBalanceTree()
		{
			return _isBalanceTree(_root);
		}
		int getHigh()
		{
			return _getHigh(_root);
		}
		bool insert(pair<K, V> kv)
		{
			Node* newnode = new Node(kv);
			if (_root == nullptr)
			{
				_root = newnode;
			}
			else
			{
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
					else
					{
						return false;
					}
				}
				if (parent->_kv.first < kv.first)
				{
					parent->_right = newnode;
					newnode->_parent = parent;
					cur = newnode;
				}
				else if (parent->_kv.first > kv.first)
				{
					parent->_left = newnode;
					newnode->_parent = parent;
					cur = newnode;
				}
				else
				{
					assert(false);
				}
				//ÅÐ¶ÏÊÇ·ñ¸üÐÂÒ¯Ò¯½Úµã,ÒÔ¼°ÅÐ¶ÏÊÇ·ñÐý×ª¡¢Ðý×ª·½Ïò
				while (parent)
				{
					if (cur == parent->_right)
					{
						parent->_bf++;
					}
					else if (cur == parent->_left)
					{
						parent->_bf--;
					}

					if (parent->_bf == 0)
					{
						break;
					}
					else if (parent->_bf == 1 || parent->_bf == -1)
					{
						cur = parent;
						parent = parent->_parent;
					}
					else if (parent->_bf == -2 && parent->_left->_bf == -1)//ÓÒµ¥Ðý
					{
						rotateR(parent);
						break;
					}
					else if (parent->_bf == 2 && parent->_right->_bf == 1)//×óµ¥Ðý
					{
						rotateL(parent);
						break;
					}
					else if (parent->_bf == -2 && parent->_left->_bf == 1)//×óÓÒË«Ðý
					{
						Node* subL = parent->_left;
						Node* subLR = subL->_right;
						int bf = subLR->_bf;
						rotateL(parent->_left);
						rotateR(parent);
						if (bf == -1)
						{
							subLR->_bf = 0;
							subL->_bf = 0;
							parent->_bf = 1;
						}
						else if (bf == 1)
						{
							subLR->_bf = 0;
							subL->_bf = -1;
							parent->_bf = 0;
						}
						else if (bf == 0)
						{
							subLR->_bf = 0;
							subL->_bf = 0;
							parent->_bf = 0;
						}
						else
						{
							assert(false);
						}
						break;
					}
					else if (parent->_bf == 2 && parent->_right->_bf == -1)//ÓÒ×óË«Ðý
					{
						Node* subR = parent->_right;
						Node* subRL = subR->_left;
						int bf = subRL->_bf;
						rotateR(parent->_right);
						rotateL(parent);
						if (bf == -1)
						{
							parent->_bf = 0;
							subR->_bf = 1;
							subRL->_bf = 0;
						}
						else if (bf == 1)
						{
							parent->_bf = -1;
							subR->_bf = 0;
							subRL->_bf = 0;
						}
						else if (bf == 0)
						{
							parent->_bf = 0;
							subR->_bf = 0;
							subRL->_bf = 0;
						}
						else
						{
							assert(false);
						}
						break;
					}
					else
					{
						assert(false);
					}
				}
			}
			return true;
		}

	private:
		void _inOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_inOrder(root->_left);
			cout << '(' << root->_kv.first << ',' << root->_kv.second << ')' << "->";
			_inOrder(root->_right);
		}
		int _getHigh(Node* root)
		{
			if (root == nullptr)
			{
				return 0;
			}

			return 1 + max(_getHigh(root->_left), _getHigh(root->_right));
		}
		bool _isBalanceTree(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}

			int leftH = _getHigh(root->_left);
			int rightH = _getHigh(root->_right);
			int highDiff = abs(leftH - rightH);

			if (rightH - leftH != root->_bf)
			{
				return false;
			}

			return highDiff < 2 && _isBalanceTree(root->_left) && _isBalanceTree(root->_right);
		}
		//Ðý×ªº¯Êý
		//ÓÒµ¥Ðý
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
			subL->_bf = parent->_bf = 0;
		}
		//×óµ¥Ðý
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
			subR->_bf = parent->_bf = 0;
		}
	private:
		Node* _root = nullptr;
	};
}