#include <stdio.h>

void print2D_Arr (int **ptr, int row, int col ) ;

int main ()
{
    int col = 0 ;
    int row = 0 ;
    int **Ptr = 0 ;
    int **Ptr1 = 0 ;
    int **sumptr = 0 ;

    printf(" Enter Nth Row , Nth Col : ");
    scanf("%d", &row);
    scanf("%d", &col);
    Ptr = (int**)calloc (row, sizeof(int * ));
    Ptr1 = (int**)calloc (row, sizeof(int * ));
    sumptr = (int**)calloc (row, sizeof(int * ));

    for (int i  = 0 ; i <row ; i ++ )
    {
        Ptr[i] = (int*)calloc (col,sizeof(int) );
        Ptr1[i] = (int*)calloc (col,sizeof(int) ) ;
        sumptr[i] = (int*)calloc (col,sizeof(int) ) ;
    }
    //--insert  data
    for (int i  = 0 ; i <row ; i ++ )
    {
        for (int j  = 0 ; j <col ; j ++ )
        {
            scanf("%d", &Ptr[i][j]) ;
        }
    }
    for (int i  = 0 ; i <row ; i ++ )
    {
        for (int j  = 0 ; j <col ; j ++ )
        {
            scanf("%d", &Ptr1[i][j]) ;
        }
    }
    //-------------sum
    //MatrixSum(Ptr1,Ptr,sumptr, row,col  );
    Matrixmult(Ptr1,Ptr,sumptr, row,col );
    //----------------
    printf("\n--------------------------------------------------------------\n");
    print2D_Arr(Ptr,row,col );
    printf("\n--------------------------------------------------------------\n");
    print2D_Arr(Ptr1,row,col );
    printf("\n--------------------------------------------------------------\n");
    print2D_Arr(sumptr,row,col );
    printf("\n--------------------------------------------------------------\n");
    return 0 ;
}
void MatrixSum (int **ptr,int **ptr1,int **sum,  int row, int col )
{
    for (int i = 0 ; i < row  ; i ++ )
    {
        for (int j = 0 ; j < col   ; j ++ )
        {
            sum [i][j]= ptr1 [i][j] +ptr [i][j] ;
        }
    }
}
void Matrixmult (int **ptr,int **ptr1,int **mult,int row, int col )
{
    long sumData = 0 ;
    for (int i = 0 ; i < row  ; i ++ )
    {

        for (int j = 0 ; j < col   ; j ++ )
        {
            //   sum += A[row][i] * B[i][col];
            sumData = 0 ;
            for (int k = 0 ; k <row ; k++ )
            {
                sumData += ptr1[i][k] * ptr[k][j] ;
            }
            mult[i][j] = sumData ;
        }
    }
}
void print2D_Arr (int **ptr, int row, int col )
{

    for (int i = 0 ; i < row  ; i ++ )
    {
        for (int j = 0 ; j < col   ; j ++ )
        {
            printf("%-2d ",ptr[i][j])  ;
        }
        printf("\n") ;
    }

}
