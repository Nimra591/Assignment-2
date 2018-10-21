#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int size=100;
int ar[1000];
void * calSum(void * start){
int sum=0;
for(int j=0,i=start;j<100;i++,j++){
sum=sum+i;
}

return (void*)sum;
}
int main(){
int sum=0;
int status_t1[10];
pthread_t thread_t1[10];
for(int x=0;x<1000;x++){
ar[x]=x+1;
}
for(int i=0;i<10;i++){
  pthread_create(&thread_t1[i],NULL,calSum,(void*)(i*size));
}
for(int i=0;i<10;i++){
  pthread_join(thread_t1[i],(void**) & status_t1[i]);
}
for(int j=0;j<10;j++){
sum=sum+status_t1[j];
}
printf("\nValue returned by thread %d\n",sum);

return 0;
}
