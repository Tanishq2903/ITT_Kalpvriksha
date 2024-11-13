import java.util.Scanner;

class Array{
    public static void main(String[] args) {
      int a = addition();
      System.out.println(a);

        
    }
    public static int addition(){
        int arr[] = new int[20];
        for(int i = 0 ; i <=2;i++){
            Scanner sc = new Scanner(System.in);
           System.out.println("Enter index first:");
           int a = sc.nextInt();
           System.out.println("Enter index last:");
           int b = sc.nextInt();
           System.out.println("Enter increment:");
           int c = sc.nextInt();


           for(int k = a;k<=b;k++){
            arr[k] = arr[k]+c;
           }
        }
        return sum(arr);

    }
    public static int sum(int[] arr){
        int sum = 0 ;
   for(int i = 0 ;  i < arr.length;i++){
    sum = sum+ arr[i];
   }
   return sum;
    }
}