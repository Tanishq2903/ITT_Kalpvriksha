class patterns{
public static void main(String[] args){
    for(int i = 0 ; i<=4 ; i++){
        for(int j = 1; j<= 4 ; j++){
            System.out.print("*");
        }
    System.out.println();
    }

 System.out.println();
  System.out.println();

    for(int i = 0 ; i<=4 ; i++){
        for(int j = 4; j>=i ; j--){
            System.out.print("*");
        }
    System.out.println();
    }
    
 System.out.println();
  System.out.println();

    for(int i = 0 ; i<=4 ; i++){
        for(int j = 0; j<=i ; j++){
            System.out.print("*");
        }
    System.out.println();
    }



 System.out.println();
  System.out.println();


  
 for(int i = 0 ; i<=4 ; i++){
    for(int j = 0 ; j<= 4-i ; j++){
        System.out.print(" ");
    }
    for(int j = 0 ; j<= i ; j++){
        System.out.print("*");
    }
    System.out.println();

 }
 System.out.println();
 System.out.println();
 System.out.println();
 System.out.println();

 for(int i = 0 ; i < 5 ; i++){
    for(int j = 0 ; j < i ; j++){
        System.out.print("*");
    }
    int spaces = 2*(5-i);
  for(int j = 0 ; j<spaces ; j++){
    System.out.print(" ");
  }
   for(int j = 0 ; j < i ; j++){
        System.out.print("*");
    }
  System.out.println();
 }
 for(int i = 4 ; i >= 0 ; i--){
    for(int j = 0 ; j < i ; j++){
        System.out.print("*");
    }
    int spaces = 2*(5-i);
  for(int j = 0 ; j<spaces ; j++){
    System.out.print(" ");
  }
   for(int j = 0 ; j < i ; j++){
        System.out.print("*");
    }
  System.out.println();
 }
  System.out.println();
   System.out.println();
    System.out.println();



   for(int i = 0 ; i<5 ; i++){
    for(int j = 0 ; j<5-i ; j++){
        System.out.print(" ");
    }
    for(int j = 0 ; j<=i ; j++){
        System.out.print(i + " ");
    }
    System.out.println();
   }

}
}