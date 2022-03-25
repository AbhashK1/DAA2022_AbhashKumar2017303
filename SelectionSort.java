import java.util.Scanner;
class SelectionSort
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
        //int c=0;
        int min;
        for(int i=0;i<n-1;i++)
        {
        	min=i;
        	for(int j=i+1;j<n;j++)
        	{
        		if(arr[j]<arr[min]) {
        			min=j;
        			c++;
        		}
        	}
        	int t=arr[i];
        	arr[i]=arr[min];
        	arr[min]=t;
        }
        System.out.println("Sorted Array: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]);
        }
        System.out.println("No. of Comparisons: "+c);
    }
}