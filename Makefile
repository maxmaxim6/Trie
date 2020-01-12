all: trie.o main.o trieD trie

trie.o:trie.c
	$ gcc -Wall -c -fPIC $^

main.o:main.c 
	$ gcc -Wall -c $^ 

trieD:myBank.o
	$ gcc -Wall -shared -o libtrie.so $^

trie:main.o 
	$ gcc -Wall main.o -L. -ltrie -o $@

clean:
	$ rm trie *o 

.PHONY: trieD clean all
