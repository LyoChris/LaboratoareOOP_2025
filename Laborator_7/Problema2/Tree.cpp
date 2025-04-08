#include "Tree.h"

template<typename T>
TreeNode<T>::TreeNode(const T& val, TreeNode<T>* par) : value(val), children(nullptr), childcount(0), capacity(0), parent(par) {}

template<typename T>
TreeNode<T>::~TreeNode() {
	for (int i = 0; i < childcount; ++i) {
		delete children[i];
	}
	delete[] children;
}

template<typename T>
void TreeNode<T>::addChild(TreeNode<T>* child) {
	if (childcount >= capacity) {
		resize();
	}
	children[childcount++] = child;
}

template<typename T>
void TreeNode<T>::insertChild(TreeNode<T>* child, int index) {
	if (index < 0 || index > childcount) {
		//std::cout << "Index out of range" << '\n';
		return;
	}
	if (childcount >= capacity) {
		resize();
	}
	for (int i = childcount; i > index; --i) {
		children[i] = children[i - 1];
	}
	children[index] = child;
	++childcount;
}

template<typename T>
void TreeNode<T>::sortChildren(bool (*cmp)(const T&, const T&)) {
	for (int i = 0;i < childcount - 1;i++) {
		for (int j = 0;j < childcount - i - 1;++j) {
			bool swap = false;
			if (cmp) {
				swap = cmp(children[j + 1]->value, children[j]->value);
			}
			else {
				swap = children[j + 1]->value < children[j]->value;
			}
			if (swap) {
				TreeNode<T>* temp = children[j];
				children[j] = children[j + 1];
				children[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void TreeNode<T>::resize() {
	capacity = (capacity == 0) ? 2 : capacity * 2;
	TreeNode<T>** newChildren = new TreeNode<T>*[capacity];
	for (int i = 0; i < childcount; ++i) {
		newChildren[i] = children[i];
	}
	delete[] children;
	children = newChildren;
}

template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::~Tree() {
	delete root;
}

template<typename T>
TreeNode<T>* Tree<T>::add_node(TreeNode<T>* parent, const T& value) {
	TreeNode<T>* newNode = new TreeNode<T>(value, parent);
	if (parent == nullptr) {
		delete root;
		root = newNode;
	}
	else {
		parent->addChild(newNode);
	}
	return newNode;
}

template<typename T>
TreeNode<T>* Tree<T>::get_node(TreeNode<T>* value) {
	return value ? value : root;
}

template<typename T>
void Tree<T>::delete_node(TreeNode<T>* node) {
	if (!node) return;
	if (node == root) {
		delete root;
		root = nullptr;
	}
	else {
		TreeNode<T>* parent = node->parent;
		for (int i = 0;i < parent->childcount; ++i) {
			if (parent->children[i] == node) {
				for (int j = i;j < parent->childcount - 1;++j) {
					parent->children[j] = parent->children[j + 1];
				}
				parent->childcount--;
				delete node;
				break;
			}
		}
	}
}

template<typename T>
TreeNode<T>* Tree<T>::find(TreeNode<T>* node, const T& value, bool (*cmp)(const T&, const T&)) {
	if (!node) return nullptr;
	if (cmp(node->value, value)) {
		return node;
	}
	for (int i = 0; i < node->childcount; ++i) {
		TreeNode<T>* found = find(node->children[i], value, cmp);
		if (found) return found;
	}
	return nullptr;
}

template<typename T>
void Tree<T>::insert(TreeNode<T>* parent, const T& value, int index) {
	if (!parent) return;
	TreeNode<T>* newNode = new TreeNode<T>(value, parent);
	parent->insertChild(newNode, index);
}

template<typename T>
void Tree<T>::sort(TreeNode<T>* node, bool (*cmp)(const T&, const T&)) {
	if (node) node->sortChildren(cmp);
}

template<typename T>
int Tree<T>::count(TreeNode<T>* node) {
	if (!node) node = root;
	if (!node) return 0;

	int total = node->childcount;
	for (int i = 0; i < node->childcount; ++i) {
		total += count(node->children[i]);
	}
	return total;
}

template<typename T>
TreeNode<T>* Tree<T>::get_root() {
	return root;
}