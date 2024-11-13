public class dnf {
    public static void main(String[] args) {
    
        int[] nums = {1,1,1,2,2,3};
        int a =  removeDuplicates(nums);
        System.out.println(a);
    }


    public static int removeDuplicates(int[] nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
}
