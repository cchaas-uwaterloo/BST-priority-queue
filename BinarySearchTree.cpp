#include <cstring>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "BinarySearchTree.hpp"
using namespace std;

typedef BinarySearchTree::DataType DataType;

//Node data constructor
BinarySearchTree::Node::Node(DataType data)
{
	val = data;
	left = nullptr;
	right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
	root_ = nullptr;
	size_ = 0;
}

static void recursiveDest(BinarySearchTree::Node* root);

BinarySearchTree::~BinarySearchTree() {
	recursiveDest(root_);
}

void recursiveDest(BinarySearchTree::Node *root)
{
	if (root == nullptr)
		return;
	if (root->left == nullptr && root->right==nullptr)
	{
		delete root;
		return;
	}
	if (root->left!=nullptr)
		return recursiveDest(root->left);
	else
		return recursiveDest(root->right);
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
	if (n->right == nullptr && n->left == nullptr)
		return 0;
	int lDepth,rDepth;
	if (n->left!=nullptr)
		lDepth = getNodeDepth(n->left);
	else
		lDepth = 0;
	if (n->right!=nullptr)
		rDepth = getNodeDepth(n->right);
	else
		rDepth = 0;

	if (lDepth>rDepth)
		return (lDepth+1);
	return (rDepth+1);
}

unsigned int BinarySearchTree::depth() const
{
	return getNodeDepth(root_);
}

unsigned int BinarySearchTree::size() const
{
	return size_;
}

DataType BinarySearchTree::max() const
{
	Node* n = root_;
	while(n->right!=nullptr)
		n=n->right;
	return n->val;
}

DataType BinarySearchTree::min() const
{
	Node* n = root_;
	while(n->left!=nullptr)
		n=n->left;
	return n->val;
}

bool BinarySearchTree::exists(DataType val) const
{
	Node* n = root_;
	if (n->val == val)
		return true;
	bool exists = false;
	while(n->val!=val && (n->left!=nullptr || n->right!=nullptr))
	{
		if (n->val > val) {
			if (n->left!=nullptr)
				n=n->left;
			else
				break;
		}
		else {
			if (n->right!=nullptr)
				n=n->right;
			else
				break;
		}
	}

	if (n->val == val)
		exists = true;

	return exists;
}

bool BinarySearchTree::insert(DataType val)
{
	Node* toAdd = new Node(val);
	if (root_ == nullptr) {
		root_ = toAdd;
		size_++;
		return true;
	}

	Node* nodeCheck = root_;

	while (val!=nodeCheck->val)
	{
		if (val<nodeCheck->val) {
			if (nodeCheck->left==nullptr){
				nodeCheck->left = toAdd;
				size_++;
				return true;
			}
			nodeCheck=nodeCheck->left;
		}
		if (val>nodeCheck->val) {
			if (nodeCheck->right==nullptr){
				nodeCheck->right = toAdd;
				size_++;
				return true;
			}
			nodeCheck=nodeCheck->right;
		}
	}
	return false;
}

bool BinarySearchTree::remove(DataType val)
{
	if (root_ == nullptr)
		return false;

	if (!exists(val))
		return false;


	bool child_is_right = true;
	bool is_right = true; //true = right, false = left
	Node* nodeCheck = root_;
	Node* nodeParent = nullptr;
	while (val!=nodeCheck->val)
	{
		if (val<nodeCheck->val) {
			nodeParent=nodeCheck;
			nodeCheck=nodeCheck->left;
			is_right= false;
		}
		if (val>nodeCheck->val) {
			nodeParent=nodeCheck;
			nodeCheck=nodeCheck->right;
			is_right = true;
		}

	}

	//leaf node
	if(nodeCheck->left == nullptr && nodeCheck->right == nullptr)
	{
	    if (nodeParent == nullptr)
	    {
	    	root_=nullptr;
	    }
	    else if (is_right)
			nodeParent->right = nullptr;
		else
			nodeParent->left = nullptr;
	}

	//one child node
	else if (nodeCheck->left == nullptr || nodeCheck->right == nullptr)
	{
	    if (nodeParent == nullptr) // root is being deleted
	    {
	        if (nodeCheck->right == nullptr) {
	        	cout << nodeCheck->left << endl;
	        	cout << "nodeCheck: "<<nodeCheck->val << endl;
	        	cout << "root_: "<<root_->val << endl;
	        	cout << root_->val << endl;
	        	cout << root_ << endl;
	        	root_ = nodeCheck->left; //this line breaks it
	        }
	        else
	        	root_ = nodeCheck->right;
	        delete nodeCheck;
        	return true;
	    }
		if (nodeCheck->right == nullptr)
			child_is_right = false;
		if (is_right)
		{
			if (child_is_right)
				nodeParent->right = nodeCheck->right;
			else
				nodeParent->right = nodeCheck->left;
		}
		else
		{
			if (child_is_right)
				nodeParent->left = nodeCheck->right;
			else
				nodeParent->left = nodeCheck->left;
		}
		delete nodeCheck;

	}

	//two child nodes
	else
	{
	      Node* toReplace =  nodeCheck->left;
	      nodeParent = nodeCheck;
	      while(toReplace->right != nullptr)
	      {
	    	nodeParent = toReplace;
	        toReplace = toReplace->right;
	      }

	    nodeCheck->val = toReplace->val;

	      if (toReplace->left==nullptr)
	    	  if (nodeParent!=nodeCheck)
	    		  nodeParent->right=nullptr;
	    	  else
	    		  nodeParent->left=nullptr;
	      else
	    	  if (nodeParent!=nodeCheck)
	    		  nodeParent->right=toReplace->left;
	    	  else
	    		  nodeParent->left=toReplace->left;
	      delete toReplace;

	}
	size_--;
	return true;
}




