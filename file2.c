#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
pid_t fork(void);
pid_t wait(int *stat_loc);
int main(){
int ar[1000];
int status;
int sumP[10];
int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
int sum=0;
int sum1=0;
pipe(fd1),pipe(fd2),pipe(fd3),pipe(fd4),pipe(fd5),pipe(fd6),pipe(fd7),pipe(fd8),pipe(fd9),pipe(fd10);
for(int i=0;i<1000;i++){
ar[i]=i+1;
}
if(pipe(fd1)==-1){
printf("failed");
return 1;
}
printf("Parent id %d\n",getpid());
int cpid=fork();
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("first child working \n");
for(int i=0;i<100;i++){
sum1=sum1+ar[i];
}
write(fd1[1],&sum1,sizeof(sum1));
close(fd1[1]);
exit(1);
}
else{
wait(&status);
printf("Parent id %d\n",getpid());
read(fd1[0],&sum1,sizeof(sum1));
close(fd1[0]);
printf("sum %d",sum1);
sumP[0]=sum1;
printf("second child created \n");
cpid=fork();
}
if(cpid==0){
sum1=0;
printf("Parent id %d\n",getpid());
printf("second child working \n");
for(int i=100;i<200;i++){
sum1=sum1+ar[i];
}
write(fd2[1],&sum1,sizeof(sum1));
close(fd2[1]);
exit(1);
}
wait(&status);
printf("Parent id %d\n",getpid());
read(fd2[0],&sum1,sizeof(sum1));
close(fd2[0]);
printf("sum %d",sum1);
sumP[1]=sum1;
printf("third child created \n");
cpid=fork();
if(cpid==0){
printf("Parent id %d\n",getpid());
sum1=0;
printf("third child working \n");
for(int i=200;i<300;i++){
sum1=sum1+ar[i];
}
write(fd3[1],&sum1,sizeof(sum1));
close(fd3[1]);
exit(1);
}
else{
wait(&status);
printf("Parent id %d\n",getpid());
read(fd3[0],&sum1,sizeof(sum1));
close(fd3[0]);
printf("sum %d",sum1);
sumP[2]=sum1;
printf("fourth child created \n");
cpid=fork();
}
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("fourth child working \n");
sum1=0;
for(int i=300;i<400;i++){
sum1=sum1+ar[i];
}
write(fd4[1],&sum1,sizeof(sum1));
close(fd4[1]);
exit(1);
}
wait(&status);
printf("Parent id %d\n",getpid());
read(fd4[0],&sum1,sizeof(sum1));
close(fd4[0]);
printf("sum %d",sum1);
sumP[3]=sum1;
printf("fifth child created \n");
cpid=fork();
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("fifth child working \n");
sum1=0;
for(int i=400;i<500;i++){
sum1=sum1+ar[i];
}
write(fd5[1],&sum1,sizeof(sum1));
close(fd5[1]);
exit(1);
}
else{
wait(&status);
printf("Parent id %d\n",getpid());
read(fd5[0],&sum1,sizeof(sum1));
close(fd5[0]);
printf("sum %d",sum1);
sumP[4]=sum1;
printf("sixth child created \n");
cpid=fork();
}
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("sixth child working \n");
sum1=0;
for(int i=500;i<600;i++){
sum1=sum1+ar[i];
}
write(fd6[1],&sum1,sizeof(sum1));
close(fd6[1]);
exit(1);
}
wait(&status);
printf("Parent id %d\n",getpid());
read(fd6[0],&sum1,sizeof(sum1));
close(fd6[0]);
printf("sum %d",sum1);
sumP[5]=sum1;
printf("seventh child created \n");
cpid=fork();
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("seventh child working \n");
sum1=0;
for(int i=600;i<700;i++){
sum1=sum1+ar[i];
}
write(fd7[1],&sum1,sizeof(sum1));
close(fd7[1]);
exit(1);
}
else{
wait(&status);
printf("Parent id %d\n",getpid());
read(fd7[0],&sum1,sizeof(sum1));
close(fd7[0]);
printf("sum %d",sum1);
sumP[6]=sum1;
printf("eighth child created \n");
cpid=fork();
}
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("eighth child working \n");
sum1=0;
for(int i=700;i<800;i++){
sum1=sum1+ar[i];
}
write(fd8[1],&sum1,sizeof(sum1));
close(fd8[1]);
exit(1);
}
wait(&status);
printf("Parent id %d\n",getpid());
read(fd8[0],&sum1,sizeof(sum1));
close(fd8[0]);
printf("sum %d",sum1);
sumP[7]=sum1;
printf("nineth child created \n");
cpid=fork();
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("nineth child working \n");
sum1=0;
for(int i=800;i<900;i++){
sum1=sum1+ar[i];
}
write(fd9[1],&sum1,sizeof(sum1));
close(fd9[1]);
exit(1);
}
else{
wait(&status);
printf("Parent id %d\n",getpid());
read(fd9[0],&sum1,sizeof(sum1));
close(fd9[0]);
printf("sum %d",sum1);
sumP[8]=sum1;
printf("tenth child created \n");
cpid=fork();
}
if(cpid==0){
printf("Parent id %d\n",getpid());
printf("tenth child working \n");
sum1=0;
for(int i=900;i<1000;i++){
sum1=sum1+ar[i];
}
write(fd10[1],&sum1,sizeof(sum1));
close(fd10[1]);
exit(1);
}

wait(&status);

printf("Parent id %d\n",getpid());
read(fd10[0],&sum1,sizeof(sum1));
close(fd10[0]);
printf("sum %d",sum1);
sumP[9]=sum1;

for(int  i=0;i<10;i++){
printf("Sum: %d",sumP[i]);
printf("\n");
sum=sum+sumP[i];

}
printf("Final sum: %d",sum);
}
