#include <stdlib.h>
#include "trie.h"

#define BITS_NUMBER sizeof(short) * 8
#define MAX_BIT 1U << (BITS_NUMBER - 1)

void create_node(trie_node **node, short value) {
	*node = malloc(sizeof(trie_node));
	(*node)->value = value;
	(*node)->left = 0;
	(*node)->right = 0;
}

void insert(short number, trie_node **head) {
	int i, digit;
	if (!(*head)) {
		create_node(head, -1);
	}
	trie_node *current = *head;
	for (i = 0; i < BITS_NUMBER; i++) {
		digit = (MAX_BIT >> i) & number;
		if (!digit) {
			if (!(current->left)) {
				create_node(&(current->left), 0);
			}
			current = current->left;
		} else {
			if (!(current->right)) {
				create_node(&(current->right), 1);
			}
			current = current->right;
		}
	}
}

short nearest(short number, trie_node *head) {
	int i, digit;
	int result = 0;
	trie_node *current = head;
	if (!head) return -1;
	for (i = 0; i < BITS_NUMBER; i++) {
		int d = MAX_BIT >> i;
		digit = (MAX_BIT >> i) & number;
		if (!digit) {
			if (current->left) {
				current = current->left;
			} else {
				result |= MAX_BIT >> i; 
				current = current->right;
			}
		} else {
			if (current->right) {
				result |= MAX_BIT >> i; 
				current = current->right;
			} else {
				current = current->left;
			}
		}
	}
	return result;
}
