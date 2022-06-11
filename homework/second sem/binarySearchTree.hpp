#pragma once

#include <iostream>

template <typename T>
class BSTNode {
public:
    BSTNode(T value)
            : value(value)
    {}

    T value;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
};

template <typename T>
class BinarySearchTree {
public:
    BinarySearchTree()
    {}

    BinarySearchTree(std::initializer_list<T> values) {
        for (const auto& v : values) {
            insert(v);
        }
    }

    ~BinarySearchTree() {
        destroy_node(root);
    }

    void insert(T x);

    BSTNode<T>* search(T x);

    void print(std::ostream& to = std::cout);

    template <typename Pred>
    inline void delete_if(Pred pred) {
        delete_if_recursively(root, pred);
    }

    inline void delete_value(T x) {
        root = delete_recursively(root, x);
    }

    inline void preorder_traversal(std::ostream& out = std::cout) {
        preorder_traversal_rec(root, out);
    }

    inline void postorder_traversal(std::ostream& out = std::cout) {
        postorder_traversal_rec(root, out);
    }

    inline void inorder_traversal(std::ostream& out = std::cout) {
        inorder_traversal_rec(root, out);
    }

    inline void print_path(T to, std::ostream& out = std::cout) {
        if (search(to) == nullptr) {
            throw std::exception();
        }
        print_path_recursively(root, to, out);
    }

private:
    template <typename Pred>
    static BSTNode<T>* delete_if_recursively(BSTNode<T>* v, Pred pred);
    static BSTNode<T>* delete_recursively(BSTNode<T>* v, T x);
    static BSTNode<T>* find_min(BSTNode<T>* v);
    static void print_path_recursively(BSTNode<T>* v, const T& to, std::ostream& out);

    static void destroy_node(BSTNode<T>* node) {
        if (node != nullptr) {
            destroy_node(node->left);
            destroy_node(node->right);
            delete node;
        }
    }
    static void preorder_traversal_rec(BSTNode<T>* v, std::ostream& out) {
        if (v != nullptr) {
            out << v->value << ' ';
            preorder_traversal_rec(v->left, out);
            preorder_traversal_rec(v->right, out);
        }
    }
    static void postorder_traversal_rec(BSTNode<T>* v, std::ostream& out) {
        if (v != nullptr) {
            postorder_traversal_rec(v->left, out);
            postorder_traversal_rec(v->right, out);
            out << v->value << ' ';
        }
    }
    static void inorder_traversal_rec(BSTNode<T>* v, std::ostream& out) {
        if (v != nullptr) {
            inorder_traversal_rec(v->left, out);
            out << v->value << ' ';
            inorder_traversal_rec(v->right, out);
        }
    }

    static void print_tree(BSTNode<T>* root, std::string indent, bool last) {
        if (root != nullptr) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            }
            else {
                std::cout << "L----";
                indent += "|  ";
            }
            std::cout << root->value << '\n';
            print_tree(root->left, indent, false);
            print_tree(root->right, indent, true);
        }
    }

    BSTNode<T>* root = nullptr;
};

template <typename T>
void BinarySearchTree<T>::insert(T x) {
    BSTNode<T>** curr = &root;
    while (*curr) {
        BSTNode<T>& node = **curr;
        if (x < node.value) {
            curr = &node.left;
        }
        else if (x > node.value) {
            curr = &node.right;
        }
        else {
            return;
        }
    }
    *curr = new BSTNode<T>(x);
}

template<typename T>
BSTNode<T>* BinarySearchTree<T>::search(T x) {
    BSTNode<T>* v = root;
    while (v != nullptr) {
        if (v->value == x) {
            return v;
        }
        else if (x < v->value) {
            v = v->left;
        }
        else {
            v = v->right;
        }
    }
    return nullptr;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::find_min(BSTNode<T>* v) {
    if (v->left != nullptr) {
        return find_min(v->left);
    }
    return v;
}

template<typename T>
void BinarySearchTree<T>::print_path_recursively(BSTNode<T>* v, const T& to, std::ostream& out)
{
    if (v == nullptr)
        return;
    std::cout << v->value << ' ';
    if (to < v->value)
        print_path_recursively(v->left, to, out);
    else if (to > v->value)
        print_path_recursively(v->right, to, out);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::delete_recursively(BSTNode<T>* v, T x) {
    if (v == nullptr) {
        return v;
    }
    if (x < v->value) {
        v->left = delete_recursively(v->left, x);
    }
    else if (x > v->value) {
        v->right = delete_recursively(v->right, x);
    }
    else {
        if (v->left == nullptr || v->right == nullptr) {
            BSTNode<T>* temp = v->left ? v->left : v->right;
            if (temp == nullptr) {
                temp = v;
                v = nullptr;
            }
            else {
                *v = *temp;
            }
            delete temp;
        }
        else {
            BSTNode<T>* temp = find_min(v->right);
            v->value = temp->value;
            v->right = delete_recursively(v->right, temp->value);
        }
    }
    return v;
}

template<typename T>
template<typename Pred>
BSTNode<T>* BinarySearchTree<T>::delete_if_recursively(BSTNode<T>* v, Pred pred)
{
    if (v != nullptr) {
        v->left = delete_if_recursively(v->left, pred);
        v->right = delete_if_recursively(v->right, pred);
        if (pred(v->value)) {
            return delete_recursively(v, v->value);
        }
        return v;
    }
    return nullptr;
}

template<typename T>
inline void BinarySearchTree<T>::print(std::ostream& to)
{
    print_tree(root, "", true);
}