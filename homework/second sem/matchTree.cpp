/**
 * Дано математическое выражение. Построить на его основе дерево по примеру,
 * приведенному в лекциях. Вывести данное выражение в префиксной и постфиксной
 * формах, используя соответствующие обходы.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <regex>

static const std::string QT = "\"";

enum class Operator {
    NONE,
    LEFT_PARENTHESES,
    RIGHT_PARENTHESES,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULUS,
};

/**
 * Токен -- оператор или число.
 */
class Token {
public:
    Token(int val) {
        this->value = val;
        this->op = Operator::NONE;
    }

    Token(Operator op) {
        this->value = 0;
        this->op = op;
    }

    Operator get_op() {
        return op;
    }

    int get_value() {
        return value;
    }

    std::string repr() {
        switch (op) {
            case Operator::PLUS: return "+";
            case Operator::MINUS: return "-";
            case Operator::MULTIPLY: return "*";
            case Operator::DIVIDE: return "/";
            case Operator::MODULUS: return "%";
            case Operator::LEFT_PARENTHESES: return "(";
            case Operator::RIGHT_PARENTHESES: return ")";
            default: return std::to_string(value);
        }
    }

private:
    int value;
    Operator op;
};

/**
 * Поток токенов.
 */
class TokenStream {
public:
    TokenStream(const std::string& expr) {
        std::string formatted_expr = std::regex_replace(expr, std::regex("\\s*([()+\\-*/%])\\s*"), " $1 ");
        std::stringstream ss(formatted_expr);
        std::string raw_token;
        while (ss >> raw_token) {
            Operator op = to_operator(raw_token);
            if (op != Operator::NONE) {
                q.push(Token(op));
            }
            else {
                q.push(Token(atoi(raw_token.c_str())));
            }
        }
    }

    Token next() {
        Token res = q.front();
        q.pop();
        return res;
    }

    bool is_empty() {
        return q.empty();
    }

private:
    static Operator to_operator(const std::string& str) {
        if (str == "+") return Operator::PLUS;
        if (str == "-") return Operator::MINUS;
        if (str == "*") return Operator::MULTIPLY;
        if (str == "/") return Operator::DIVIDE;
        if (str == "%") return Operator::MODULUS;
        if (str == "(") return Operator::LEFT_PARENTHESES;
        if (str == ")") return Operator::RIGHT_PARENTHESES;
        return Operator::NONE;
    }

    std::queue<Token> q;
};


/**
 * Узел дерева.
 */
struct Node {
    Node* left;
    Node* right;
    Token value;
};

void _delete_tree(Node* root);

/**
 * Наращивание дерева вынесено в отдельную функцию
 * для возможности рекурсивного вызова.
 */
void _expand(Node*& root, TokenStream& tokens) {
    while (!tokens.is_empty()) {
        auto t = tokens.next();
        switch (t.get_op())
        {
            case Operator::NONE: // t -- число
            {
                if (root == nullptr) {
                    root = new Node{nullptr, nullptr, t};
                }
                else if (root->right == nullptr) {
                    root->right = new Node{nullptr, nullptr, t};
                }
                else {
                    auto n = root->right;
                    while (n->right != nullptr) {
                        n = n->right;
                    }
                    n->right = new Node{nullptr, nullptr, t};
                }
                break;
            }

            case Operator::MULTIPLY:
            case Operator::DIVIDE:
            case Operator::MODULUS:
            {
                if (root->value.get_value()) {
                    auto n = root;
                    root = new Node{n, nullptr, t};
                }
                else {
                    auto n = new Node{root->right, nullptr, t};
                    root->right = n;
                }
                break;
            }

            case Operator::PLUS:
            case Operator::MINUS:
            {
                auto n = root;
                root = new Node{n, nullptr, t};
                break;
            }

            case Operator::LEFT_PARENTHESES:
            {
                Node* subroot = nullptr;
                _expand(subroot, tokens);
                if (root == nullptr) {
                    root = subroot;
                }
                else if (root->right == nullptr) {
                    root->right = subroot;
                }
                else {
                    auto n = root->right;
                    while (n->right != nullptr) {
                        n = n->right;
                    }
                    n->right = subroot;
                }
                break;
            }

            case Operator::RIGHT_PARENTHESES:
                return;

            default:
                std::cerr << "Woops! How did you do that?!\n";
        }
    }
}

/**
 * Вывод дерева в удобочитаемом формате.
 */
void pretty_print_tree(Node* root, std::string indent, bool last, std::ostream& to = std::cout) {
    if (root != nullptr) {
        to << indent;
        if (last) {
            to << "R----";
            indent += "   ";
        }
        else {
            to << "L----";
            indent += "|  ";
        }
        to << (root->value.get_op() != Operator::NONE ?
               QT + root->value.repr() + QT :
               root->value.repr()) << '\n';
        pretty_print_tree(root->left, indent, false, to);
        pretty_print_tree(root->right, indent, true, to);
    }
}

/**
 * Прямой обход.
 */
void preorder_traversal(Node* n, std::ostream& out = std::cout) {
    if (n != nullptr) {
        out << n->value.repr() << ' ';
        preorder_traversal(n->left, out);
        preorder_traversal(n->right, out);
    }
}

/**
 * Обратный обход.
 */
void postorder_traversal(Node* n, std::ostream& out = std::cout) {
    if (n != nullptr) {
        postorder_traversal(n->left, out);
        postorder_traversal(n->right, out);
        out << n->value.repr() << ' ';
    }
}

int main()
{
    // ввод математического выражения
    std::cout << "Enter your mathematical expression.\n"
                 ">>> ";
    std::string raw_expr;
    std::getline(std::cin, raw_expr);

    Node* root = nullptr;
    TokenStream tokens(raw_expr);
    // забор токенов из потока, наращивание дерева
    _expand(root, tokens);

    // вывод дерева тремя различными способами
    std::cout << "A tree built looks like this:\n";
    pretty_print_tree(root, "", true);

    std::cout << "\nPreorder traversal (prefix notation):\n";
    preorder_traversal(root);

    std::cout << "\nPostorder traversal (postfix notation):\n";
    postorder_traversal(root);

    // очистка памяти
    _delete_tree(root);
    return 0;
}

void _delete_tree(Node* root) {
    if (root != nullptr) {
        _delete_tree(root->left);
        _delete_tree(root->right);
        delete root;
    }
}