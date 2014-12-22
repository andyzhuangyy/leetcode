#include <iostream>
#include <cstring>
using namespace std;
//
//increase
void merge(int A[], int m, int B[], int n) {
    //bool isinc;
    if (0 == m) {
        memcpy(A, B, sizeof(int) * n);
        return;
    }

    if (0 == n) {
        return;
    }
    //if (1 == m && 1 == n) {
        //A[1] = B[0];
        //return;
    //}
    //if (m > 1)
        //isinc = A[1] > A[0];
    //else
        //isinc = B[1] > B[0];

    //isinc = true;


    int i = m - 1;
    int j = n - 1;
    for (; i >= 0 && j >= 0; ) {
        //if (isinc) {
            if (B[j] > A[i]) {
                A[i + j + 1] = B[j];
                --j;
            }
            else {
                A[i + j + 1] = A[i];
                --i;
            }
        //}
        //else {
            //if (B[j] > A[i]) {
                //A[i + j + 1] = A[i];
                //--i;
            //}
            //else {
                //A[i + j + 1] = B[j];
                //--j;
            //}
        //}

        continue;
    }

    if (i < 0) {
        memcpy(A, B, sizeof(int) *(j + 1));
    }


}



int main()
{
#define M 1
#define N 1
    int a[M+N] = {2};
    int b[] = {1};
    merge(a, 1, b, 1);

    for(int i = 0; i < M+N; ++i)
        printf("%d ", a[i]);
    return 0;
}
