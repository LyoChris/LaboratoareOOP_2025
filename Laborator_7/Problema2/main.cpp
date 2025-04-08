#include <iostream>
#include "Tree.cpp"

bool int_equals(const int& a, const int& b) {
    return a == b;
}

bool reverse_sort(const int& a, const int& b) {
    return a > b;
}

int main() {
    Tree<int> tree;

    TreeNode<int>* root = tree.add_node(nullptr, 10);
    TreeNode<int>* n1 = tree.add_node(root, 5);
    TreeNode<int>* n2 = tree.add_node(root, 15);
    TreeNode<int>* n3 = tree.add_node(n1, 3);
    TreeNode<int>* n4 = tree.add_node(n1, 7);
    TreeNode<int>* n5 = tree.add_node(n2, 12);
    TreeNode<int>* n6 = tree.add_node(n2, 20);

    std::cout << "Added nodes to the tree.\n";


    tree.insert(root, 8, 1);
    std::cout << "Inserted node 8 at index 1 under root.\n";

    std::cout << "Count from root: " << tree.count(nullptr) << "\n";
    std::cout << "Count from node n1: " << tree.count(n1) << "\n";


    TreeNode<int>* found = tree.find(tree.get_root(), 7, int_equals);
    if (found) {
        std::cout << "Found node with value 7.\n";
    }
    else {
        std::cout << "Node with value 7 not found.\n";
    }

    TreeNode<int>* maybe_root = tree.get_node(nullptr);
    std::cout << "Get node returned root value: " << maybe_root->value << "\n";

    std::cout << "Sorting root children in ascending order...\n";
    tree.sort(root);

    std::cout << "Children of root after default sort: ";
    for (int i = 0; i < root->childcount; ++i) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";

    std::cout << "Sorting root children in descending order...\n";
    tree.sort(root, reverse_sort);

    std::cout << "Children of root after reverse sort: ";
    for (int i = 0; i < root->childcount; ++i) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";


    std::cout << "Deleting node with value 5 (and its children)...\n";
    tree.delete_node(n1);

    std::cout << "Count from root after deletion: " << tree.count(nullptr) << "\n";

    return 0;
}