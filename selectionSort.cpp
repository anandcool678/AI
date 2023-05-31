#include <bits/stdc++.h>
using namespace std;


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, mini;
	for (i = 0; i < n-1; i++)
	{
		mini = i;
		for (j = i+1; j < n; j++)
		{
		if (arr[j] < arr[mini])
			mini = j;
		}
		if (mini!=i)
			swap(&arr[mini], &arr[i]);
	}

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}


int main()
{
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
	selectionSort(arr,n);
	return 0;
}
