#include<stdio.h>
int  search(int a_count, int* a,int data ,int pos,int *min , int *max){
    int flage = 0 ;
    *min = pos ;
  for (int i = pos+1 ; i < a_count ; i ++){
      if (a[i]==data){
          *max = i ;
          return 0 ;
      }
  }
 return  -1 ;

}
int MohamedAbs(int data ){
    if (data > 0 ){
        return data ;
    }
        return 0 ;

}
int minimumDistances(int a_count, int* a) {
    int min = 0   , max = 0 , diff = -1;
    for (int i = 0 ; i< a_count ; i ++ ){
        min = 0   , max = 0 ;
       if (search( a_count, a,a[i],i, &min, &max)==-1)continue;
        if (i == 0 ){
            diff = MohamedAbs(max-min)  ;
            }
        else if (diff >= MohamedAbs(max-min))  {
          diff = MohamedAbs(max-min) ;
        }
        printf(" %d ,  %d , %d\n", max,min, diff ) ;
    }


 return diff;
}
int main (){
int data [2000] ;
int size = 0 ;
scanf("%d",&size);
int i = 0 ;
while (size){

  scanf("%d",data+i);
  i++ ;
  size-- ;
}
minimumDistances(i  ,data ) ;

return 0 ;
}
