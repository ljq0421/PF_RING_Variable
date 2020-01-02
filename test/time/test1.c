#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
  time_t t1,t2;
  t1=time(0);
  t2=time(0);
  printf("%d %d\n",t1,t2);
  while(t2-t1<2)
    t2=time(0);
  printf("%d %d\n",t1,t2);
  return 0;
}
