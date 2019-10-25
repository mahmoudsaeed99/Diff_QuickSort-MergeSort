#include <bits/stdc++.h>
#include <iostream>
#include <ctime>

using namespace std;


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//-----------------------------------------------------------------------
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;}
        else{
            arr[k] = R[j];
            j++;}
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//---------------------------------------
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
//----------------------------------------------
void Random (int arr[],int Size,int range)
{
    srand((unsigned)time(0));

    for(int i=0; i<Size; i++){
        arr[i] = (rand()%range)+1;
    }
}

//---------------------------------------------------
MergeTime(int arr[],int l ,int r)
{

 clock_t start = clock();
 mergeSort(arr,l,r);
 clock_t end = clock();
 double time =((double)(end-start)/CLOCKS_PER_SEC)*1000;
 return time;
}
//---------------------------------------------------------
QuickTime(int arr[],int low ,int high)
{

 clock_t start = clock();
 quickSort(arr,low,high);
 clock_t end = clock();
 double time =((double)(end-start)/CLOCKS_PER_SEC)*1000;
 return time;
}

int main()
{
 cout<<"OK"<<endl;
int x=0;
while(x<5)
{

 int Size;
 cout<< "enter size of  array?" << endl;
 cin >> Size;

 int arr[Size];
 Random(arr,Size,100000);

 cout << MergeTime(arr,0,Size-1)<<endl;
 cout << QuickTime(arr,0,Size-1)<<endl;
 x++;
    }


    return 0;
}
