import java.util.*;

public class statements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = n % 2;
        if (m == 0) {
            System.out.println("even");
        } else {
            System.out.println("odd");
        }
    }
}
