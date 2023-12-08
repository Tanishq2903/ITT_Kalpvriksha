import java.util.Scanner;
class tree{
   static Scanner sc = null;
 public static void main(String[] args) {
    sc = new Scanner(System.in);
   Node root =  insert();
    InTraversal(root);
    System.out.println();
    PostTraversal(root);
    System.out.println();
    PreTraversal(root);
    System.out.println();
 }
 public static class Node{
    
    Node left;
    Node right;
    int data;
   public Node(int data){
        this.data = data;
    }
   
 }
 public static Node insert(){
    Node root = null;
    
   
    System.out.println("enter data:");
    int data = sc.nextInt();
    if(data == -1) return null;
    root = new Node(data);
    System.out.println("enter left" + data);
    root.left  = insert();
    System.out.println("enter right" + data);
    root.right = insert();
    return root;

 }
 public static void InTraversal(Node root){
   if(root == null) return ;
   InTraversal(root.left);
   System.out.println(root.data);
   InTraversal(root.right);
 }
 public static void PreTraversal(Node root){
    if(root == null) return ;
    System.out.println(root.data);
    PreTraversal(root.left);
   
    PreTraversal(root.right);
  }
  public static void PostTraversal(Node root){
    if(root == null) return ;
    PostTraversal(root.left);
  
    PostTraversal(root.right);
    System.out.println(root.data);
  }


}