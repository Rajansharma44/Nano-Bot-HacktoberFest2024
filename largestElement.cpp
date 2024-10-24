import java.util.*;

public class largestElement {
    public static void main (String [] args){
        Scanner sc = new Scanner (System.in);
        System.out.print("enter the number of elements in the array");
        int n = sc.nextInt();
        int[] numbers = new int [n];
        System.out.print("enter the elements of array");
        for (int i= 0; i<n; i++){
            numbers[i]=sc.nextInt();
        }
        int max = numbers[0];
        for (int i=1; i<numbers.length; i++){
            if (numbers[i] > max){
                max = numbers[i];
            }
        }
        System.out.println ("the largest element is: " + max);
        sc.close();
    }
}
