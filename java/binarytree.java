import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class binarytree {
    static Scanner sc = null;
    public static void main(String[] args) {
        sc = new Scanner(System.in);
       Node root =  insert();
      int a =  diameterOfBinaryTree( root);
      System.out.println(a);
    //    in(root);
    //    System.out.println();
    //    post(root);
    //    System.out.println();
    //    pre(root);
    //    System.out.println();
    //    level(root);
    //    System.out.println(1);
        
    }
    private static class Node{
        Node left;
        Node right;
        int data;
        public Node(int data){
            this.data = data;
        }
    }
        public static Node insert(){
            System.out.println("enter data:");
            int data = sc.nextInt(); 
            if(data == -1) return null;
            Node root = new Node(data);
          
           System.out.println("enter left of" + data);
         root.left = insert();
           System.out.println("enter right" + data);
           root.right = insert();
   return root;


        }
//         public static void in(Node root){
//             if(root == null) return;
//             in(root.left);
//             System.out.print(root.data);
//             in(root.right);

//         }
//         public static void pre(Node root){
//             if(root == null) return;
//             System.out.print(root.data);
//             in(root.left);
//             in(root.right);

//         }
//         public static void post(Node root){
//             if(root == null) return;
//             in(root.left);
//            in(root.right);
//            System.out.print(root.data);

//         }
//         public static void level(Node root){
//             Queue <Node> q = new LinkedList<Node>();
//             q.add(root);
//             while(!q.isEmpty()){
//                 Node curr = q.poll();
//                 System.out.print(curr.data);
//                  if(curr.left != null){
//                   q.add(curr.left);
//                  }
//                  if(curr.right != null){
//                     q.add(curr.right);
//                    }
            // }
                
            
//         }
    
// }
static int max = 0;
    
    public static int diameterOfBinaryTree(Node root) {
        maxDepth(root);
        return max;
    }
    
    private static int maxDepth(Node root) {
        if (root == null) return 0;
        
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        
        max = Math.max(max, 1+left + right);
        
        return Math.max(left, right) + 1;
    }
}