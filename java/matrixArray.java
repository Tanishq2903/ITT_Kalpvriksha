import java.util.Arrays;

public class matrixArray {
   public static void main(String[] args) {
        // int[][] arr = {
        //         {10, 20, 30, 40},
        //         {15, 25, 35, 45},
        //         {28, 29, 37, 49},
        //         {33, 34, 38, 50}
        // };
        int[][] arr = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {12,14,15,16}
        };

        System.out.println(Arrays.toString(search(arr,7 )));
    }

    // static int[] search(int[][] matrix, int target) {
    //     int r = 0;
    //     int c = matrix[0].length - 1;

    //     while (r < matrix.length && c >= 0) {
    //         if (matrix[r][c] == target) {
    //             return new int[]{r, c};
    //         }
    //         if (matrix[r][c] < target) {
    //             r++;
    //         } else {
    //             c--;
    //         }
    //     }
    //     return new int[]{-1, -1};
    // }
    static int[] search(int arr[][] , int target){
        int row = arr.length ;
        int col = arr[0].length;
        if(row == 1){
       System.out.println(Arrays.toString(binary(arr , 0 , col-1 , target)));
        }


    }

    private static int[] binary(int[][] arr, int i, int j, int target) {
        while(i < j){
            if
        }
        return null;
    }
}
