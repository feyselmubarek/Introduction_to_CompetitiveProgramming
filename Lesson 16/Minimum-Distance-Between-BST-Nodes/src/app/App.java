package app;

public class App {
    public static void main(String[] args) throws Exception {
        TreeNode treeNode = new TreeNode(90);
        treeNode.left = new TreeNode(69);
        treeNode.right = new TreeNode(6);

        treeNode.left.right = new TreeNode(89);
        treeNode.left.left = new TreeNode(49);
        treeNode.left.left.right = new TreeNode(52);

        System.out.println(new Solution().minDiffInBST(treeNode));
    }
}