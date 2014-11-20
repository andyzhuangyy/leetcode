CC = g++ -g
PROGS = valid_palindrome\
		pasical_triangle_ii\
		pasical_triangle\

all: $(PROGS)

clean:
	rm -f $(PROGS)
	rm -rf *.dSYM
