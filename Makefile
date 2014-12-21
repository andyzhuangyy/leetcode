CC = g++ -g
PROGS = valid_palindrome\
		pasical_triangle_ii\
		pasical_triangle\
		minimum_depth\
		balance_btree\
		binary_tree_level_order_tranversal\
		symmetric_tree\

all: $(PROGS)

clean:
	rm -f $(PROGS)
	rm -rf *.dSYM
