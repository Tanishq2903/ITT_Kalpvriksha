import java.util.Scanner;

public class ques {
    public static Void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int c = sc.nextInt();
        int b = sc.nextInt();
        int average = (a + b + c) % 3;
        System.out.println(average);
    }

}
