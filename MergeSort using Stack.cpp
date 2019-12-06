#include <bits/stdc++.h>
using namespace std;
enum type{MERGE,MERGESORT};
class Node
{
    public:
    int st,ennd;
    type Type;
    Node(int start,int End ,type TYPE)
    {
        st=start;
        ennd=End;
        Type=TYPE;
    }
};
void Merge(int arr[], int low, int middle, int high)
{
    int x = middle - low + 1;
    int z = high - middle;
    int Left[x], Right[z];
    for (int i = 0; i < x; i++)
    {
      Left[i] = arr[low + i];
    }
    for (int j = 0; j < z; j++)
    {
      Right[j] = arr[middle + 1 + j];
    }
    int i=0, j=0, k=low;
    while (i < x && j < z)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < x)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < z)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
void MergeSort(int n, int arr[])
{
    Node node(0,n-1,MERGESORT);
    stack<Node> s;
    s.push(node);
    while(!s.empty())
    {
        Node cn=s.top();
        s.pop();
        int st = cn.st;
        int End = cn.ennd;
        int mid = (st + End)/2;
        if(cn.ennd-cn.st<1)
        {
            continue;
        }
        if(cn.Type==MERGESORT)
        {
            s.push(Node(st,End,MERGE));
            s.push(Node(st,mid,MERGESORT));
            s.push(Node(mid+1,End,MERGESORT));
        }
        else
        {
            Merge(arr,st, mid, End);
        }
    }
}

int main()
{
	cout<<"Please Enter the number of elements you want to insert:"<<endl;
    int n; cin>>n;
    int* arr= new int [n];
    cout<<"Please Enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    MergeSort(n,arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
	delete[] a;
    return 0;
}
