/*
* Bitwise trie implementation.
* 
* A very basic bitwise trie implementation that supports
*	insert and nearest.
*
* More information on tries: https://en.wikipedia.org/wiki/Trie
*/

typedef struct trie_node {
	int value;
	struct trie_node *left;
	struct trie_node *right;
} trie_node;

/*
*	Inserts a given short to a given bitwise trie. 
*/
void insert(short number, trie_node **head);


/*
* Finds the 'bitwise' nearest short to a given short
* in a given bitwise trie.
*/
short nearest(short number, trie_node *head);
