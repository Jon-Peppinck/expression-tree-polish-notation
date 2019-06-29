#include <stack>

using namespace std;

class ETNode {
public:
    ETNode() { left = right = 0; }
    ETNode(const char& e, ETNode *l = 0, ETNode *r = 0) 
		{ el = e, left = l, right = r; }
    char el;
    ETNode *left, *right;
};

// A very simple expression tree class that converts a parenthesized input 
// consisting of addition and multiplication operations, into an expression tree.
// Traversal of this expression tree generates various Polish notations.

class Expression_Tree { 
public:
	Expression_Tree() { root = 0; };
	~Expression_Tree() { clear(root); }
	void build_expression_tree(char[], int);
	void inorder() { inorder(root); }
	void preorder() { preorder(root); }
	void postorder() {postorder(root); }
private:
	ETNode* root;
	stack<ETNode*> tree_stack;
	void visit(ETNode*);
	void inorder(ETNode*);
	void preorder(ETNode*);
	void postorder(ETNode*);
	void clear(ETNode*);
};

