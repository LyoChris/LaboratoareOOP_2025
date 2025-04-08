#pragma once

template<typename T>
class TreeNode {
public:
	T value;
	TreeNode<T>** children;
	int childcount;
	int capacity;
	TreeNode<T>* parent;

	TreeNode(const T& val, TreeNode<T>* parent = nullptr);
	~TreeNode();

	void addChild(TreeNode<T>* child);
	void insertChild(TreeNode<T>* child, int index);
	void sortChildren(bool (*cmp)(const T&, const T&) = nullptr);

private:
	void resize();
	
};

template<typename T>
class Tree {
private:
	TreeNode<T>* root;

public:
	Tree();
	~Tree();

	TreeNode<T>* add_node(TreeNode<T>* parent, const T& value);
	TreeNode<T>* get_node(TreeNode<T>* value);
	void delete_node(TreeNode<T>* node);
	TreeNode<T>* find(TreeNode<T>* node, const T& value, bool (*cmp)(const T&, const T&));
	void insert(TreeNode<T>* parent, const T& value, int index);
	void sort(TreeNode<T>* node, bool (*cmp)(const T&, const T&) = nullptr);
	int count(TreeNode<T>* node);
	TreeNode<T>* get_root();
};

