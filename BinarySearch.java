package Test3;

import java.util.Scanner;

public class BinarySearch {
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
		int l=0,u=arr.length-1;
		int mid=(l+u)/2;
		while(l<=u)
		{
			c+=1;
			if(arr[mid]<x)
				u=mid+1;
			else if(arr[mid]==x)
			{
				System.out.println("Element Found at position "+(mid+1));
				return c;
			}
			else
				l=mid-1;
			mid=(u+l)/2;
			if(u>l)
			{
				System.out.println("Element not found");
				return c;
			}
		}
		return c;
	}
	public static void main(String[] args)
	{
		BinarySearch ob=new BinarySearch();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Size of Array ");
		int n=sc.nextInt();
		int[] arr= new int[n];
		ob.input(arr, n);
		int x=ob.search(arr);
		System.out.println("Number of Comparison "+x);
	}

}
