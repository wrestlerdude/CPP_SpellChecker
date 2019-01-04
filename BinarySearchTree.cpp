/*
* Author: Raish Allan, 40316824
* Last Modified: 15/04/2018
* 
*  Methods for binary tree library.
*/
#include <string>
#include "bst.h"

// Creates an empty binary tree
BinarySearchTree::BinarySearchTree()
{

}

// Creates a binary tree with an initial value to store
BinarySearchTree::BinarySearchTree(std::string word)
{
	this->root = new Node;
	this->root->data = word;
}

//Creates a deep-copy of the tree recursively
Node* copy_recursive(const Node *node)
{
	if (!node)
		return NULL;
	Node *copy = new Node;
	copy->data = std::string(node->data);
	copy->left = copy_recursive(node->left);
	copy->right = copy_recursive(node->right);
	return copy;
}

// Creates a binary tree by copying an existing tree
BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	this->root = copy_recursive(rhs.root);
}

//Recursive helper to free memory of the tree
void destroy_recursive(Node *node)
{
	if (node)
	{
		destroy_recursive(node->left);
		destroy_recursive(node->right);
		delete node;
		node = nullptr;
	}
}

// Destroys (cleans up) the tree
BinarySearchTree::~BinarySearchTree()
{
    destroy_recursive(this->root);
}

//Insert recursive helper to insert data in a node of the tree
void insert_recursive(Node **node, std::string &word)
{
	//if current node doesn't exist then add new node to the tree with data
	if (!(*node))
	{
		*node = new Node;
		(*node)->data = std::string(word);
		(*node)->left = nullptr;
		(*node)->right = nullptr;
	}
	//go down left branch of parent
	else if (word < (*node)->data) 
		insert_recursive(&(*node)->left, word);
	//go down right branch of parent
	else if (word > (*node)->data)
		insert_recursive(&(*node)->right, word);
}

// Adds a word to the tree
void BinarySearchTree::insert(std::string word)
{
	if (word.size() > 0)
		insert_recursive(&this->root, word);
}

//Recursive remover for removing a specific node
void remove_helper(Node *&node, const std::string word)
{
	//if node doesn't exist
	if (!node)
		return;
	//go down left branch
	else if (word < node->data) remove_helper(node->left, word);
	//go down right branch
	else if (word > node->data) remove_helper(node->right, word);
	else
	{
		//if the node has no children
		if (!node->left && !node->right)
		{
			delete node;
			node = nullptr;
		//if node has only a right child
		}else if (!node->left)
		{
			Node *temp = node->right;
			delete node;
			node = temp;
		//if node only has a left child
		}else if (!node->right)
		{
			Node *temp = node->left;
			delete node;
			node = temp;
		//if node has both children
		}else
		{
			//go down the right child and find the smallest node (smallest value in larger branch)
			Node *temp = node->right;
			while (temp->left)
				temp = temp->left;
			//replace the parent's position and cleanup
			node->data = temp->data;
			remove_helper(node->right, temp->data);
		}
	}
}

// Removes a word from the tree
void BinarySearchTree::remove(std::string word)
{
	remove_helper(this->root, word);
}

//Search function returns a node if it is found
Node* search(Node *node, const std::string word)
{
 	if (!node || node->data == word)
       return node;

    if (node->data < word)
       return search(node->right, word);

    return search(node->left, word);
}

// Checks if a word is in the tree
bool BinarySearchTree::exists(std::string word) const
{
    return (search(this->root, word) != NULL);
}

//Recursive helper for inorder
void inorder_recursive(Node *node, std::string &word)
{
	if (node)
	{
		inorder_recursive(node->left, word);
		word += node->data + " ";
		inorder_recursive(node->right, word);
	}
}

// Prints the tree to standard out in numerical order
std::string BinarySearchTree::inorder() const
{
	if (!this->root)
		return "";
	std::string word;
	inorder_recursive(this->root, word);
	word.pop_back();
	return word;
}

//Recursive helper for preorder
void preorder_recursive(Node *node, std::string &word)
{
	if (node)
	{
		word += node->data + " ";
		preorder_recursive(node->left, word);
		preorder_recursive(node->right, word);
	}
}

// Prints the tree in pre-order
std::string BinarySearchTree::preorder() const
{
	if (!this->root)
		return "";
    std::string word;
	preorder_recursive(this->root, word);
	word.pop_back();
	return word;
}

//Recursive helper for postorder
void postorder_recursive(Node *node, std::string &word)
{
	if (node)
	{
		postorder_recursive(node->left, word);
		postorder_recursive(node->right, word);
		word += node->data + " ";
	}
}

// Prints the tree in post-order
std::string BinarySearchTree::postorder() const
{
    if (!this->root)
		return "";
    std::string word;
	postorder_recursive(this->root, word);
	word.pop_back();
	return word;
}

//Recursive operator overload helper for equals
bool equal_to(Node* lhs, Node* rhs)
{
	//if both nodes are null they are equal
    if (!lhs && !rhs)
        return 1;
 	//recursively goes down the tree matching the data of every nodes in each respective position
    if (lhs && rhs)
        return (lhs->data == rhs->data && equal_to(lhs->left, rhs->left) && equal_to(lhs->right, rhs->right));
 
    return 0;
} 

// Checks if two trees are equal
bool BinarySearchTree::operator==(const BinarySearchTree &other) const
{
    return (equal_to(this->root, other.root));
}

// Checks if two trees are not equal
bool BinarySearchTree::operator!=(const BinarySearchTree &other) const
{
    return (!equal_to(this->root, other.root));
}

// Reads in words from an input stream into the tree
std::istream& operator>>(std::istream &in, BinarySearchTree &tree)
{
    std::string word;
    while (in >> word)
    	tree.insert(word);
    return in;
}

// Writes the words, in-order, to an output stream
std::ostream& operator<<(std::ostream &out, const BinarySearchTree &tree)
{ 
	std::string str = tree.inorder();
	return out << str;
}
