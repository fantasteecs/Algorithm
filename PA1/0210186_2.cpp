#include <iostream>
//#define ss 6
using namespace std;

int* quick_find_2d_peak(int **B, int r0, int c0, int n);
int main()
{

     /* int B[][6]={{1, 2, 2, 2, 8, 12},
                  {1, 8, 7, 2, 11, 2},
                  {2, 2, 2, 2, 2, 2},
                  {2, 2, 2, 2, 2, 2},
                  {1, 9, 2, 2, 10, 2},
                  {10, 2, 2, 2, 5, 2}};*/

    /* int B[][2]={{1,2},
                 {3,5}};*/

    /*int B[][1]={{5}};*/

   /*  int B[][7]={{1, 2, 3, 2, 9, 2, 2},
                 {1, 8, 2, 5, 8, 2, 2},
                 {2, 9, 10, 2, 2, 2, 2},
                 {2, 2, 2, 2, 2, 2, 2},
                 {1, 2, 5, 2, 6, 2, 2},
                 {1, 2, 2, 2, 5, 2, 2},
                 {2, 2, 2, 2, 2, 2, 2}};*/

    cout<<"Input the size of 2D array : \n";

    int size;
    cin>>size;

    cout<<"Input the element : \n";
    int **B = new int*[size];
    for(int i=0;i<size;i++)
    {
        B[i] = new int[size];
        for(int j=0;j<size;j++)
        {
            cin>>B[i][j];
        }

    }

    int* peak = quick_find_2d_peak(B,0,0,size);
    cout  <<"\n\n====Peak====\nrow:" << peak[0]<<"\ncolumn:"<<peak[1]<<"\nvalue:"<<peak[2] << endl;
    return 0;
}


int* quick_find_2d_peak(int **B, int r0, int c0, int n)
{
    int mid_r = r0+n/2;
    int mid_c = c0+n/2;
    int Max = B[r0][mid_c];
    int Max_r = r0, Max_c = mid_c;

    if(n%2==1)
    {
        int end_scan = r0+n;
        for(int i=r0+1;i<end_scan;i++)
        {
            if(B[i][mid_c]>Max)
            {
                Max = B[i][mid_c];
                Max_c = mid_c;
                Max_r = i;
            }

        }
        int scan_num = n+c0;
        for(int i=c0;i<scan_num;i++)
        {
            if(B[mid_r][i]>Max)
            {
                Max = B[mid_r][i];
                Max_c = i;
                Max_r = mid_r;
            }
        }

      /*  cout<<Max_r<<endl;
        cout<<Max_c<<endl;
        cout<<Max<<endl<<endl;*/
        int peak[3];
        peak[0]=Max_r;
        peak[1]=Max_c;
        peak[2]=B[Max_r][Max_c];


        if(Max_c==mid_c)
        {
            if(Max_r==mid_r)
                return peak;

            else if(B[Max_r][mid_c-1]<=B[Max_r][Max_c] && B[Max_r][Max_c]>=B[Max_r][mid_c+1])
                return peak;




                //從mid出發，決定下一區

            else if(B[Max_r][Max_c-1]>B[Max_r][Max_c])
            {
                if(Max_r<mid_r)
                    {//cout<<"lucc"<<endl;
                    return quick_find_2d_peak(B,mid_r-(n-1)/2,mid_c-(n-1)/2,(n-1)/2);
                    }
                else
                    {//cout<<"ldcc"<<endl;
                    return quick_find_2d_peak(B,mid_r+1,mid_c-(n-1)/2,(n-1)/2);
                    }
            }
            else// if(B[Max_r][mid+1]>B[Max_r][Max_c])
            {
                if(Max_r<mid_r)
                    {//cout<<"rucc"<<endl;
                    return quick_find_2d_peak(B,mid_r-(n-1)/2,mid_c+1,(n-1)/2);
                    }
                else
                    {//cout<<"rdcc"<<endl;
                    return quick_find_2d_peak(B,mid_r+1,mid_c+1,(n-1)/2);
                    }
            }
        }
        else
        {
            if(B[mid_r-1][Max_c]<=B[Max_r][Max_c] && B[Max_r][Max_c]>=B[mid_r+1][Max_c])
                return peak;

            else if(B[Max_r-1][Max_c]>B[Max_r][Max_c])
            {
                if(Max_c<mid_c)
                    {//cout<<"lurr"<<endl;
                    return quick_find_2d_peak(B,mid_r-(n-1)/2,mid_c-(n-1)/2,(n-1)/2);
                    }
                else
                    {//cout<<"rurr"<<endl;
                    return quick_find_2d_peak(B,mid_r-(n-1)/2,mid_c+1,(n-1)/2);
                    }
            }
            else// if(B[mid+1][Max_c]>B[Max_r][Max_c])
            {
                if(Max_c<mid_c)
                    {//cout<<"ldrr"<<endl;
                    return quick_find_2d_peak(B,mid_r+1,mid_c-(n-1)/2,(n-1)/2);
                    }
                else
                    {//cout<<"rdrr"<<endl;
                    return quick_find_2d_peak(B,mid_r+1,mid_c+1,(n-1)/2);
                    }
            }
        }
    }
    else
    {

        int end_scan = r0+n;
        int scan_num = n+c0;
        for(int j=0;j<2;j++)
        {
            for(int i=r0+1;i<end_scan;i++)
            {
                if(B[i][mid_c-j]>Max)
                {
                    Max = B[i][mid_c-j];
                    Max_c = mid_c-j;
                    Max_r = i;
                }

            }

            for(int i=c0;i<scan_num;i++)
            {
                if(B[mid_r-j][i]>Max)
                {
                    Max = B[mid_r-j][i];
                    Max_c = i;
                    Max_r = mid_r-j;
                }
            }
        }

        /*cout<<Max_r<<endl;
        cout<<Max_c<<endl;
        cout<<Max<<endl<<endl;*/
        int peak[3];
        peak[0]=Max_r;
        peak[1]=Max_c;
        peak[2]=B[Max_r][Max_c];

        if(Max_c==mid_c && Max_r==mid_r) return peak;
        if(Max_c==mid_c-1 && Max_r==mid_r) return peak;
        if(Max_c==mid_c && Max_r==mid_r-1) return peak;
        if(Max_c==mid_c-1 && Max_r==mid_r-1) return peak;

        if(Max_c==mid_c)
        {
            if(B[Max_r][Max_c]>=B[Max_r][Max_c+1])
                return peak;
            else
            {
                if(Max_r<mid_r)
                    {//cout<<"rucc"<<endl;
                    return quick_find_2d_peak(B, mid_r-n/2, mid_c+1, (n-2)/2);
                    }
                else
                    {//cout<<"rdcc"<<endl;
                    return quick_find_2d_peak(B,   mid_r+1, mid_c+1, (n-2)/2);
                    }
            }
        }
        if(Max_c==mid_c-1)
        {
            if(B[Max_r][Max_c]>=B[Max_r][Max_c-1])
                return peak;
            else
            {
                if(Max_r<mid_r)
                    {//cout<<"lucc"<<endl;
                    return quick_find_2d_peak(B, mid_r-n/2,  mid_c-n/2, (n-2)/2);
                    }
                else
                    {//cout<<"ldcc"<<endl;
                    return quick_find_2d_peak(B,   mid_r+1,  mid_c-n/2, (n-2)/2);
                    }
            }
        }
        if(Max_r==mid_r)
        {
            if(B[Max_r][Max_c]>=B[Max_r+1][Max_c])
                return peak;
            else
            {
                if(Max_c<mid_c)
                    {//cout<<"ldrr"<<endl;
                    return quick_find_2d_peak(B, mid_r+1,  mid_c-n/2, (n-2)/2);
                    }
                else
                    {//cout<<"rdrr"<<endl;
                    return quick_find_2d_peak(B, mid_r+1,  mid_c+1, (n-2)/2);
                    }
            }
        }
        if(Max_r==mid_r-1)
        {
            if(B[Max_r][Max_c]>=B[Max_r-1][Max_c])
                return peak;
            else
            {
                if(Max_c<mid_c)
                    {//cout<<"lurr"<<endl;
                    return quick_find_2d_peak(B, mid_r-n/2,  mid_c-n/2, (n-2)/2);
                    }
                else
                    {//cout<<"rurr"<<endl;
                    return quick_find_2d_peak(B, mid_r-n/2,  mid_c+1, (n-2)/2);
                    }
            }
        }

    }


}
