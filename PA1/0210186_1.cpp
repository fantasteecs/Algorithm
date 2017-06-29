#include <iostream>

using namespace std;

int quick_find_1d_peak(int *A, int i, int j);
int main()
{
    //int A[] = {1, 3, 3, 4, 8, 2};
    cout<<"Input the size of 1D array : \n";

    int size;
    cin>>size;

    cout<<"Input the element : \n";
    int *A = new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }

    int p = quick_find_1d_peak(A, 0, size-1);
    cout << "\n\n====Peak====\nindex:" << p << "\nvalue:" << A[p]  << endl;
    return 0;
}
int quick_find_1d_peak(int *A, int i, int j)
{
    int m = (i+j)/2;
    if(m==0)    //剩第一個or前兩個
    {
        if(A[0]<A[1]) return 1;
        else return 0;
    }
    if(i==j)    //剩最後一個
    {
        return i;
    }
    else if( A[m]>=A[m-1] && A[m]>=A[m+1] )
        return m;
    else if(A[m]<A[m-1])
        return quick_find_1d_peak(A, i, m-1);
    else if(A[m]<A[m+1])
        return quick_find_1d_peak(A, m+1, j);

}


