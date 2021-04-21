#pragma once
#include <string>
#include <iostream>

template<typename T>
class CNode
{
private:
	int count;				// ������� ��� ����������� ������ ��������
	T value;		// �������
	CNode* left, * right;	// ��������� �� ���� � ����� � ������
public:
	CNode(T val, CNode* l, CNode* r);		// ����������� � �����������

	CNode* addNode(CNode* tree, T val);	// ���������� �����

	void deleteNode(CNode* tree, T node);	// �������� �����
	void deleteSubTree(CNode* subTreee);			// �������� �����

	CNode* min(CNode* tree);						// ����� �������� 
	CNode* max(CNode* tree);						// ����� ���������

	CNode* find(CNode* start, T findVal, int* count);	// ����� �������� � ������

	bool isBinaryTree(CNode* tree);					// �������� �������� �� ��� ������ �������� 
	bool check(CNode* node, int min, int max);

	void PrintTree(CNode* root);					// ������� ������ � ������� � ����� �� ����� 
};

template<typename T>
inline CNode<T>::CNode(T val, CNode* l, CNode* r)
{
	value = val;
	left = l;
	right = r;
	count = 1;
}

template<typename T>
inline CNode<T>* CNode<T>::addNode(CNode<T>* tree, T val)
{
	if (tree == nullptr)
	{
		tree = new CNode(val, nullptr, nullptr);
		tree->value = val;
		tree->left = nullptr;
		tree->right = nullptr;
		tree->count = 1;
	}
	else
	{
		if (val == tree->value)
		{
			tree->count++;
		}
		if (tree->value > val)
		{
			tree->left = addNode(tree->left, val);
		}
		else
		{
			if (tree->value < val)
			{
				tree->right = addNode(tree->right, val);
			}
		}
	}

	return tree;
}

template<typename T>
inline void CNode<T>::deleteNode(CNode<T>* tree, T node)
{
	CNode<T>* tmp;
	if (tree != nullptr)
	{
		if (tree->value > node)
		{
			while (tree->left != nullptr)
			{
				tmp = tree;
				tree = tree->left;
				if (tree->value == node)
				{
					tree = tmp;
					delete tree->left;
					if (tree->left->left == nullptr)
					{
						tree->left = tree->left->left;
						return;
					}
					else
					{
						// ���� ������� ��������� ������� � ������
						tree->left = nullptr;
						return;
					}
				}
			}
		}
		else
		{
			if (tree->value < node)
			{
				while (tree->right != nullptr)
				{
					tmp = tree;
					tree = tree->right;
					if (tree->value == node)
					{
						tree = tmp;
						delete tree->right;
						if (tree->right->right == nullptr)
						{
							tree->right = tree->right->right;
							return;
						}
						else
						{
							// ���� ������� ��������� ������� � ������
							tree->right = nullptr;
							return;
						}
					}
				}
			}
		}
	}
}

template<typename T>
inline void CNode<T>::deleteSubTree(CNode<T>* start)
{
	if (start != nullptr)
	{
		deleteSubTree(start->left);
		deleteSubTree(start->right);
		delete start;
	}
}

template<typename T>
inline CNode<T>* CNode<T>::min(CNode<T>* tree)
{
	T res;
	if (tree != nullptr)
	{
		if (tree->left == nullptr)
		{
			res = tree->value;
		}
		while (tree->left != nullptr)
		{
			tree = tree->left;
			res = tree->value;
		}
	}
	std::cout << "MIN: " << res << "\n";
	return tree;
}

template<typename T>
inline CNode<T>* CNode<T>::max(CNode<T>* tree)
{
	T res;
	if (tree != nullptr)
	{
		if (tree->right == nullptr)
		{
			res = tree->value;
		}
		while (tree->right != nullptr)
		{
			tree = tree->right;
			res = tree->value;
		}
	}
	std::cout << "MAX: " << res << "\n";
	return tree;
}

template<typename T>
inline CNode<T>* CNode<T>::find(CNode<T>* start, T findVal, int* count)
{
	if (start != nullptr)
	{
		if (findVal == start->value) 
		{ 
			*count = (*count) + start->count;
			std::cout << "Slovo: '" << findVal << "' Find: " << *count << " raz" << "\n"; 
		}
		find(start->right, findVal, count);
		find(start->left, findVal, count);
	}
	return start; 
}

template<typename T>
inline bool CNode<T>::isBinaryTree(CNode<T>* tree)
{
	return check(tree, 0, 0);
}

template<typename T>
inline bool CNode<T>::check(CNode<T>* node, int min, int max)
{
	return false;
}

template<typename T>
inline void CNode<T>::PrintTree(CNode<T>* root)
{
	if (root != nullptr)
	{
		std::cout << root->value << " ";
		PrintTree(root->right);
		PrintTree(root->left);
	}
}