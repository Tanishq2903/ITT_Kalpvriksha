import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leet {
    public static void main(String[] args) {
        String digits = "29";
        System.out.println(letterCombinations(digits));
    }
   
    public static List<String> letterCombinations(String digits) {
        List<String>ans = new ArrayList<>();
        if(digits.length() == 0)return ans;
        String[]arr = {"1","2","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        String output = new String();
       solve(ans,digits,arr,"",index);
        
        return ans;
    }
    public static void solve( List<String>ans ,String digits,String[]arr,String output,int index){
        if(index >= digits.length()){
            ans.add(output);
            return;
        }
        int number = Character.getNumericValue(digits.charAt(index));
        String s = arr[number];
        for(int i = 0 ; i < s.length();i++){
            output = output + (s.charAt(i));
            solve(ans,digits,arr,output,index+1);
           output = output.substring(0, output.length() - 1);
        }
    }
        
}
