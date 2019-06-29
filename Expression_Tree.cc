#include "Expression_Tree.h" 
#include <iostream>

using namespace std;

void Expression_Tree::build_expression_tree(char input[], int size) 
{ 
	ETNode *temp, *first_item, *second_item, *third_item;

	for (int i = 0; i < size; i++) {
		if (input[i] != ')') {
			// Create tree nodes from array unless ')'
			temp = new ETNode;
			temp->el = input[i];
			// Add tree nodes to stack
			tree_stack.push(temp);
		} else {
			// If ')' found, pop three items off the stack
			first_item = tree_stack.top();
			tree_stack.pop();
			second_item = tree_stack.top();
			tree_stack.pop();
			third_item = tree_stack.top();
			tree_stack.pop();
			// Construct subtree with the second item as its root
			second_item->left = third_item;
			second_item->right = first_item;
			// Free and remove left parenthesis from the stack
			delete tree_stack.top();
			tree_stack.pop();
			// Add the root-node to the stack
			tree_stack.push(second_item);
		}
	}
	// Build Expression Tree
	while(tree_stack.size() != 1) {
		// Pop 3 items off stack
		first_item = tree_stack.top();
		tree_stack.pop();
		second_item = tree_stack.top();
		tree_stack.pop();
		third_item = tree_stack.top();
		tree_stack.pop();
		// Construct subtree with the second item as its root
		second_item->left = third_item;
		second_item->right = first_item;
		// Add the root-node to the stack
		tree_stack.push(second_item);		
	}
	// Single tree node will be the root-node
	root = second_item;
	// Complete expression tree
	tree_stack.push(second_item);
}

void Expression_Tree::visit(ETNode* p) 
{ 
	cout << p->el; 
} 

void Expression_Tree::inorder(ETNode *p) 
{
     if (p != 0) {
       	inorder(p->left);
       	visit(p);
       	inorder(p->right);
     }
}

void Expression_Tree::preorder(ETNode *p) 
{
    if (p != 0) {
    	visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

void Expression_Tree::postorder(ETNode* p) 
{
    if (p != 0) {
   	postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

void Expression_Tree::clear(ETNode *p) 
{
    if (p != 0) {
   	clear(p->left);
       	clear(p->right);
    	delete p;
	}
}
