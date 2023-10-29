#pragma once
namespace m
{
	template<class K>
	class BSTreeNode
	{
		template<class K>
		friend class BSTree;
	public:
		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	private:
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;
	};


	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		/*BSTree()
		{}*/
		BSTree() = default;

		~BSTree()
		{
			_destroy(_root);
			_root = nullptr;
		}

		BSTree(const BSTree<K>& t)
		{
			_copy(_root,t._root);
		}

		BSTree<K>& operator=(const BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		void inOrder()
		{
			_inOrder(_root);
			cout << endl;
		}
		bool find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		bool insert(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
			if (parent == nullptr)//判断BSTree是否为空
			{
				_root = cur;
			}
			else
			{
				if (parent->_key < key)
				{
					parent->_right = cur;
				}
				else
				{
					parent->_left = cur;
				}
			}
			return true;
		}
		bool erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)//处理删除根节点，且二叉平衡树只有这一个根节点的情况
						{
							Node* del = cur;
							_root = _root->_right;
							delete del;
							return true;
						}
						if (parent->_key > cur->_key)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
						delete cur;
						return true;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							Node* del = cur;
							_root = _root->_left;
							delete del;
							return true;
						}
						if (parent->_key > cur->_key)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
						return true;
					}
					else
					{
						Node* min = cur->_right;
						Node* minParent = cur;
						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}
						swap(cur->_key, min->_key);
						if (min == minParent->_left)
						{
							minParent->_left = min->_right;
						}
						else
						{
							minParent->_right = min->_right;
						}
						delete min;
						return true;
					}
				}
			}
			return false;
		}
		bool findRecursion(const K& key)
		{
			return _findRecursion(_root, key);
		}
		bool insertRecursion(const K& key)
		{
			return _insertRecursion(_root, key);
		}
		bool eraseRecursion(const K& key)
		{
			return _eraseRecursion(_root, key);
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
			root = nullptr;
		}
		void _copy(Node*& root, Node* const& copy)
		{
			if (copy == nullptr)
			{
				return;
			}

			root = new Node(copy->_key);
			_copy(root->_left, copy->_left);
			_copy(root->_right, copy->_right);
		}
		void _inOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_inOrder(root->_left);
			cout << root->_key << " ";
			_inOrder(root->_right);
		}
		bool _findRecursion(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key < key)
			{
				return _findRecursion(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _findRecursion(root->_left, key);
			}
			else
			{
				return true;
			}

		}
		bool _insertRecursion(Node*& root, const K& key)//这里的引用很巧妙
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
			{
				return _insertRecursion(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _insertRecursion(root->_left, key);
			}
			else
			{
				return false;
			}
		}
		bool _eraseRecursion(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key < key)
			{
				return _eraseRecursion(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _eraseRecursion(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
					delete del;
					del = nullptr;
					return true;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
					delete del;
					del = nullptr;
					return true;
				}
				else
				{
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}
					swap(root->_key, min->_key);
					return _eraseRecursion(root->_right, min->_key);
				}

			}
		}
	private:
		Node* _root = nullptr;
	};
}