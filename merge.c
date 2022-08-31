#include<stdio.h>
int binary_search(int search_key,int a[],int n)
{
	int mid,i,l,h,c=0;
	l=0;
	h=n-1;
	mergesort(a,l,h);
	while(l<=h)
	{
		mid=(l+h)/2.0;
		if(search_key==a[mid])
		{
			c++;
			break;
		}
		else if(search_key<=a[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	if(c==1)
		printf("Search key=%d Found!\n",search_key);
	else
		printf("Not found\n");
}
void merge(int arr[],int lb,int mid,int ub)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	int b[100];
	while(i<=mid && j<=ub)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++)
	{
		arr[k]=b[k];
	}
}

void mergesort(int a[],int lb,int ub)
{
	int mid=(lb+ub)/2;
	if(lb<ub)
	{
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}

void print(int a[],int n)
{
	int i;
	printf("After sorting array elements are : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{
	int a[50],n,i,low,high,search_key;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	printf("\nEnter the array elements : \n");
	for(i=0;i<n;i++)
	{
		printf("No. %d Element is = ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter the search element : ");
	scanf("%d",&search_key);
	//low=0;
	//high=n-1;
	binary_search(search_key,a,n);
	mergesort(a,low,high);
	print(a,n);
	//return 0;
	
}
