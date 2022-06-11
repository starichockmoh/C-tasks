#pragma once

#include <iostream>

#define max(a, b) ((a > b) ? a : b)

template <typename T>
class AVLNode {
public:
    T value;
    AVLNode* left;
    AVLNode* right;
    int height;

    bool is_leaf() {
        return left == nullptr && right == nullptr;
    }
};

template <typename T>
int height(AVLNode<T>* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

template <typename T>
AVLNode<T>* new_node(T value) {
    auto node = new AVLNode<T>();
    node->value = value;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

template <typename T>
AVLNode<T>* right_rotate(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

template <typename T>
AVLNode<T>* left_rotate(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

template <typename T>
int get_balance_factor(AVLNode<T>* n) {
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

template <typename T>
AVLNode<T>* insert_node(AVLNode<T>* node, T value) {
    if (node == nullptr)
        return new_node(value);
    if (value < node->value)
        node->left = insert_node(node->left, value);
    else if (value > node->value)
        node->right = insert_node(node->right, value);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance_factor = get_balance_factor(node);
    if (balance_factor > 1) {
        if (value < node->left->value) {
            return right_rotate(node);
        }
        else if (value > node->left->value) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
    }
    if (balance_factor < -1) {
        if (value > node->right->value) {
            return left_rotate(node);
        }
        else if (value < node->right->value) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
    }
    return node;
}

template <typename T>
AVLNode<T>* find_min(AVLNode<T>* node) {
    AVLNode<T>* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template <typename T>
AVLNode<T>* delete_node(AVLNode<T>* root, T value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->value) {
        root->right = delete_node(root->right, value);
    }
    else {
        if (root->left == nullptr || root->right == nullptr) {
            AVLNode<T>* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp;
            }
            delete temp;
        }
        else {
            AVLNode<T>* temp = find_min(root->right);
            root->value = temp->value;
            root->right = delete_node(root->right, temp->value);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance_factor = get_balance_factor(root);
    if (balance_factor > 1) {
        if (get_balance_factor(root->left) >= 0) {
            return right_rotate(root);
        }
        else {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }
    if (balance_factor < -1) {
        if (get_balance_factor(root->right) <= 0) {
            return left_rotate(root);
        }
        else {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }
    return root;
}

template <typename T>
void print_tree(AVLNode<T>* root, std::string indent, bool last) {
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

template <typename T>
class AVLTree {
public:
    AVLTree() {}
    AVLTree(std::initializer_list<T> values) {
        for (const auto& v : values) {
            insert(v);
        }
    }

    ~AVLTree() {
        destroy_node(root);
    }

    AVLNode<T>* search(T x);
    void insert(T x);
    void delete_value(T x);
    void print(std::ostream& to = std::cout);
    T leaves_sum();

    inline void inorder_traversal(std::ostream& out = std::cout) {
        inorder_traversal_rec(root, out);
    }

    inline void preorder_traversal(std::ostream& out = std::cout) {
        preorder_traversal_rec(root, out);
    }

private:
    static void destroy_node(AVLNode<T>* n) {
        if (n != nullptr) {
            destroy_node(n->left);
            destroy_node(n->right);
            delete n;
        }
    }

    static void inorder_traversal_rec(AVLNode<T>* v, std::ostream& out) {
        if (v != nullptr) {
            inorder_traversal_rec(v->left, out);
            out << v->value << ' ';
            inorder_traversal_rec(v->right, out);
        }
    }

    static void preorder_traversal_rec(AVLNode<T>* v, std::ostream& out) {
        if (v != nullptr) {
            out << v->value << ' ';
            preorder_traversal_rec(v->left, out);
            preorder_traversal_rec(v->right, out);
        }
    }

    static T leaves_sum_recursive(AVLNode<T>* v) {
        if (v == nullptr)
            return T();
        if (v->is_leaf())
            return v->value;
        return leaves_sum_recursive(v->left) + leaves_sum_recursive(v->right);
    }

    AVLNode<T>* root = nullptr;
};

template <typename T>
AVLNode<T>* AVLTree<T>::search(T x)
{
    AVLNode<T>* v = root;
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
void AVLTree<T>::insert(T x)
{
    root = insert_node(root, x);
}

template <typename T>
void AVLTree<T>::delete_value(T x)
{
    root = delete_node(root, x);
}

template<typename T>
inline void AVLTree<T>::print(std::ostream& to)
{
    print_tree(root, "", true);
}

template<typename T>
inline T AVLTree<T>::leaves_sum()
{
    return leaves_sum_recursive(root);
}
