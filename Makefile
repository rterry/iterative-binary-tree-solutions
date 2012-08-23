CFLAGS=-Wall -g

obj= main.o utils.o treefunctions.o 
NP_List_Problems: $(obj) treeheader.h
	cc -o NP_BinaryTree_Problems $(obj) treeheader.h
	@echo "make complete"

main.o:
utils.o:
treefunctions.o:

clean:
	rm -f cd $(obj)
	@echo "cd, $(obj) files are removed"

