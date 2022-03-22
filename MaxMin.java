import java.util.*;
class MaxMin
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Size of Array");
        int n=sc.nextInt();
        int A[]=new int[n];
        int max=0,min=0;
        for(int i=0;i<n;i++)
        {
            A[i]=sc.nextInt();
        }
        max=min=A[0];
        for(int i=0;i<n;i++)
        {
            if(A[i]<min)
            min=A[i];
            if(A[i]>max)
            max=A[i];
        }
        System.out.println("Max: "+max+"\nMin: "+min);
    }
}