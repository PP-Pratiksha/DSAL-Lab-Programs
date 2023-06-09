#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	int n;
	int ch;
	do
	{
		cout<<"Enter array size:";
		cin>>n;
		int arr[n];
		cout<<"Enter elements of an array:";
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<"Heap sort on array:";
		heapSort(arr,n);
		printArray(arr,n);
		cout<<"\nDo you want to continue....(1/-1)";
		cin>>ch;
	}while(ch!=-1);
	cout<<"\nThank You for using this program!!!";
	return 0;
}
