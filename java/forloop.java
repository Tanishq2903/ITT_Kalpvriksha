import java.util.Scanner;

public class forloop {
    public static void main(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 1;i<=n; i += 5){
            System.out.println(n);
        }
    }
}
