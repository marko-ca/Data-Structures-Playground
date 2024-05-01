class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

class BinarySearchTree {
    
    private TreeNode root;

    public TreeNode getRoot() {
        return root;
    }

    public void insert(int value) {
        root = insert_recursive(root, value);
    }

    private TreeNode insert_recursive(TreeNode root, int value) {

        if (root == null) {
            return new TreeNode(value);
        }

        if (value < root.val) {
            root.left = insert_recursive(root.left, value);
        }else if (value > root.val) {
            root.right = insert_recursive(root.right, value);
        }

        return root;
    }

    public boolean search(int value) {
        return search_recursive(root, value);
    }

    private boolean search_recursive(TreeNode root, int value) {
        if (root == null) {
            return false;
        }

        if (root.val == value) {
            return true;
        }

        if (value < root.val) {
            return search_recursive(root.left, value);
        } else {
            return search_recursive(root.right, value);
        }
    }

    public int delete(int value) {
        root = delete_recursive(root, value);
        return root.val;
    }

    private TreeNode delete_recursive(TreeNode root, int value) {
        if (root == null) {
            return null;
        }

        if (value < root.val) {
            root.left = delete_recursive(root.left, value);
        } else if (value > root.val) {
            root.right = delete_recursive(root.right, value);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            // Node to delete has two children
            root.val = findMin(root.right).val;
            root.right = delete_recursive(root.right, root.val);
        }
        return root;
    }

    private TreeNode findMin(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    // works for display the tree
    public void in_order_traversal(TreeNode root) {
        if(root == null) {
            return;
        }else {
            in_order_traversal(root.left);
            System.out.print(root.val + ",");
            in_order_traversal(root.right);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        System.out.println("Inserting value");
        bst.insert(4);
        bst.insert(6);
        bst.insert(5);
        bst.insert(8);
        System.out.println("In-order traversal:");
        bst.in_order_traversal(bst.getRoot());
        System.out.println();
        System.out.println("Inserting value again");
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(1);
        bst.insert(9);
        System.out.println("In-order traversal:");
        bst.in_order_traversal(bst.getRoot());
        System.out.println();
        System.out.println("Root value: " + bst.getRoot().val);
        System.out.println("Search for value 6:");
        System.out.println(bst.search(6)); // Output: true because 6 is in the tree
        System.out.println("Delete value 6:");
        bst.delete(6);
        System.out.println("Search for value 6 again:");
        System.out.println(bst.search(10)); // Output: false because 6 no longer exists
        bst.insert(0);

        System.out.println("In-order traversal now:");
        bst.in_order_traversal(bst.getRoot());
    }
}