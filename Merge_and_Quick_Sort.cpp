#include<iostream>
using namespace std;
void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}
void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;

    int len1=mid-s+1;
    int len2=e-mid;
    int arr1[len1],arr2[len2];

    int k=s;
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        arr2[i]=arr[k++];
    }

    int i=0,j=0;
    k=s; 
    while(i<len1 && j<len2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k++]=arr1[i++];
        }
        else
        {
            arr[k++]=arr2[j++];
        }
    }
    while(i<len1)
    {
        arr[k++]=arr1[i++];   
    }
    while(j<len2)
    {
        arr[k++]=arr2[j++];
    }

}
void mergeSort(int *arr,int s,int e)
{
    // Base Case
    if(s>=e)
    {
        return ;
    }
    // Recursive Case
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}


int partition(int *arr,int s,int e)
{
    int i=s-1;
    int pivot=arr[e];
    for(int j=s;j<e;j++)
    {
        if(pivot>arr[j])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(pivot,arr[i+1]);
    return i+1;
}
void quickSort(int *arr,int s,int e)
{
    // Base Case
    if(s>=e)
    {
        return ;
    }
    // Recursive Case
    int p=partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}


int main()
{
int arr[]={10,9,8,7,6,5,4,3,2,1};
int n=sizeof(arr)/sizeof(arr[0]);
mergeSort(arr,0,n-1);
printArray(arr,n);
cout<<endl;
quickSort(arr,0,n-1);
printArray(arr,n);
return 0;
}