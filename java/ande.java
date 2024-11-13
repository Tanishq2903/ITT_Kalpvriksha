import java.util.HashSet;
import java.util.Set;

public class ande {
    public static boolean main(String[] args) {
        String s = "abc" ;
        String t = "ahbgdc";
            Set<Character> set = new HashSet<>();
            for(int i = 0 ; i<t.length();i++){
                set.add(t.charAt(i));
                i++;
            } 
     
            for(int i =0; i<s.length() ; i++){
                if(!set.contains(s.charAt(i))) {return false;}
                else {i++;}
            }
            return true;
         }
 }

