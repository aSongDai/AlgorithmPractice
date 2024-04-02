
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};


class Solution
{
public:
	bool IsFull(TreeNode* root)
	{
		// 
		if (root->left != nullptr && root->right == nullptr)
		{
			return false;
		}
		if (root->left == nullptr && root->right != nullptr)
		{
			return false;
		}

		auto leftStatus = IsFull(root->left);
		auto rightStatus = IsFull(root->right);

		return leftStatus && rightStatus;
	}
};