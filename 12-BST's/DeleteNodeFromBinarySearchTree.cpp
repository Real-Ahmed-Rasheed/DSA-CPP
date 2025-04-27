TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root->val == key){

            //0 child
            if(root->left == NULL && root->right == NULL){
                //it is a leaf so delete
                delete root;
                return NULL;
            }

            //1 Childe
                    //left child
                    if(root->left != NULL && root->right == NULL){
                        TreeNode* temp = root->left;
                        delete root;
                        return temp;
 
                    }
                    //right child
                    if(root->left == NULL && root->right != NULL){
                        TreeNode* temp = root->right;
                        delete root;
                        return temp;
 
                    }
            // 2 Child
            //replace node to delete (root) with the largest from left subtree
                    if(root->left != NULL && root->right != NULL){
                        TreeNode* temp = root->left;
                        //find the largest in left subtree
                        while(temp->right != NULL){
                            temp = temp->right;
                        }
                        int largest = temp->val;
                        //replace root's val with largest from left subT
                        root->val = largest;
                        
                        //now call to delete the largest from left subT
                        root->left = deleteNode(root->left, largest);
                        return root;
                    }
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        } else{
            root->left = deleteNode(root->left, key);
        }
        return root;
        
    }