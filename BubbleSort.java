import java.util.*;
class BubbleSort
{
    public static void main(String[] args)
    {
        int c=0;
    	Scanner sc=new Scanner(System.in);
        System.out.println("Enter Size: ");
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int t=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=t;
                    c++:
                }
            }
        }
        System.out.println("Sorted Array: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]);
        }
        System.out.println("No. of Comparisons: "+c);
    }
}
