expression_tree: expression_tree_test.o expression_tree.o
	g++ expression_tree_test.o Expression_Tree.o -o expression_tree

expression_tree.o: Expression_Tree.cc Expression_Tree.h
	g++ -g -c Expression_Tree.cc

expression_tree_test.o: expression_tree_test.cc Expression_Tree.h
	g++ -g -c expression_tree_test.cc

clean:
	rm expression_tree_test.o Expression_Tree.o expression_tree_test
