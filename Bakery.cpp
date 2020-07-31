#include(pthread.h)
#include(stdio.h>
#include(unistd.h>
#include (assert.h>
volatile int NUM_THREADS = 10;
volatile int Number[10] = {0};
volatile int count_cs[10] = {0};
volatile int Entering[10] = {0};

int max()
{
int i = 0;
int j = 0;
int maxvalue = 0;
for(i = 0; i < 10; i++)
{
if ((Number[i]) > maxvalue)
{
maxvalue = Number[i];
}
}
return maxvalue;
}
lock(int i)
{
int j;
Entering[i] = 1;
Number[i] = 1 + max();
Entering[i] = 0;
for (j = 1; j <= NUM_THREADS; j++)
{
while (Entering[j]) { } /* Do nothing */
while ((Number[j] != 0) &&
((Number[j] < Number[i]) ||
((Number[j] == Number[i]) && (j < i)))) { }
}
}
unlock(int i) {
Number[i] = 0;
}
void Thread(int i) {
while (1) {
lock(i);
count_cs[i+1] = count_cs[i+1] + 1 ;
//printf("critical section of %d\n", i+1);
unlock(i);
}
}
int main()
{
int duration = 10000;
pthread_t threads[NUM_THREADS];
int rc;
long t;
for(t = 0; t < NUM_THREADS; t++){
printf("In main: creating thread %ld\n", t+1);
rc = pthread_create(&threads[t], NULL, Thread, (int)t);
if (rc){
printf("ERROR; return code from pthread_create() is %d\n", rc);
exit(-1);
}
}
usleep(duration*1000);
for(t=0; t < NUM_THREADS; t++)
{
printf("count of thread no %d is %d\n",t+1,count_cs[t+1]);
}
return 0;
}
