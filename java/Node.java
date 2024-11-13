public class Node {
    Node [] children;
    boolean eow;
    public Node(){
        children = new Node[26];
        for(int i = 0 ; i < 26 ; i++){
            children[i] = null;
        }
        eow = false;
    }
    static Node root = new Node();





    public static void insert(String s){
        Node curr = root;
        for(int i = 0 ; i < s.length();i++){
            int idx = s.charAt(i) - 'a';
            if(curr.children[idx] == null){
               curr.children[idx] = new Node(); 
            }
            if(i == s.length()-1){
                curr.children[idx].eow = true;
            }
            curr = curr.children[idx];

        }
        
    }
    public static boolean search(String s){
  Node curr = root;
        for(int i = 0 ; i < s.length();i++){
            int idx = s.charAt(i) - 'a';
            Node node = curr.children[idx];
            if(node == null){
              return false;
            }
            if(i == s.length()-1 &&  node.eow == false){
            return false;
            }
            curr = curr.children[idx];
            
          
        }
        return true;

    }
    public static boolean ans(String a){
        if(a.length() == 0)return true;
        for(int i = 1 ; i < a.length();i++){
            String first = a.substring(0,i);
            String second = a.substring(i);
            if(search(first) && ans(second)){
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        String words[] = {"the","a","there","their","any"};
  for(int i = 0 ; i < words.length;i++){
    insert(words[i]);
  }
  
  System.out.println(ans("itheretheir"));
    }
    }
