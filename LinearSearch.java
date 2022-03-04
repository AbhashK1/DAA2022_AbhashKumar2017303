package Test3;
import java.util.*;
public class LinearSearch {
	void input(int arr[],int n)
	{
		Scanner s=new Scanner(System.in);
		for(int i=0;i<n;i++)
		{
			arr[i]=s.nextInt();
		}
	}
	int search(int arr[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Value to be Searched");
		int x=sc.nextInt();
		int c=0;
		for(int i=0;i<arr.length;i++)
		{
			c+=1;
			if(arr[i]==x)
			{
				System.out.println("Value Found at Posititon "+(i+1));
				return c;
			}
		}
		System.out.println("Value Not Found");
		return c;
	}
	public static void main(String[] args)
	{
		LinearSearch ob=new LinearSearch();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Size of Array ");
		int n=sc.nextInt();
		int[] arr= new int[n];
		ob.input(arr, n);
		int x=ob.search(arr);
		System.out.println("Number of Comparison "+x);
	}
}
