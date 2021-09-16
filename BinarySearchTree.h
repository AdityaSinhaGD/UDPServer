#pragma once
#include <queue>
#include <string>
#include "Util.h"

class BinarySearchTree {

private:
	struct TreeNode {
		int data;
		TreeNode* left;
		TreeNode* right;

		TreeNode() : data(0), left(nullptr), right(nullptr) {};
		TreeNode(int _data) : data(_data), left(nullptr), right(nullptr) {};
		TreeNode(int _data, TreeNode* leftSubtree, TreeNode* rightSubtree) :data(_data), left(leftSubtree), right(rightSubtree) {};
	};

public:
	TreeNode* root;
	BinarySearchTree() {
		root = nullptr;
	}

	TreeNode* Insert(TreeNode* root, int data) {
		if (root == nullptr) {
			TreeNode* newNode = new TreeNode(data);
			return newNode;
		}
		if (root->data > data) {
			root->left = Insert(root->left, data);
		}
		else {
			root->right = Insert(root->right, data);
		}
		return root;
	}

	bool IsIdentical(TreeNode* root, TreeNode* otherRoot) {

		if (root == nullptr && otherRoot == nullptr) {
			return true;
		}
		else if (root == nullptr && otherRoot != nullptr) {
			return false;
		}
		else if (root != nullptr && otherRoot == nullptr) {
			return false;
		}
		else {
			if (root->data == otherRoot->data && IsIdentical(root->left, otherRoot->left) && IsIdentical(root->right, otherRoot->right)) {
				return true;
			}
			else {
				return false;
			}
		}

	}

	void EncodeBSTToString(TreeNode* root, std::string& encodedString) {

		if (root == nullptr) {
			return;
		}

		std::queue<TreeNode*> treeNodeQueue;
		treeNodeQueue.push(root);

		while (!treeNodeQueue.empty()) {

			int currentLevelSize = treeNodeQueue.size();
			std::vector<int> currentLevel;

			for (int i = 0; i < currentLevelSize; i++) {

				TreeNode* currentNode = treeNodeQueue.front();
				treeNodeQueue.pop();

				encodedString += std::to_string(currentNode->data) + ",";

				currentLevel.push_back(currentNode->data);

				if (currentNode->left != nullptr) {
					treeNodeQueue.push(currentNode->left);
				}

				if (currentNode->right != nullptr) {
					treeNodeQueue.push(currentNode->right);
				}
			}

		}
		encodedString.pop_back();
	}

	TreeNode* DecodeBSTFromString(const std::string& inputString) {
		std::vector<int> nums;
		StringToNumVector(inputString, ',', nums);
		for (auto& num : nums) {
			root = Insert(root, num);
		}
		return root;
	}

};