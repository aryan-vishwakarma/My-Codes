#include <stdio.h>
#include <pthread.h>
#include <math.h>
void* isPrime(void* num) {
    int n = *((int*)(&num));
    int f = 1;
    if (n > 2)
        for (int i = 2; i < (int)sqrt(n) + 1; i++) {
            if (n % i == 0) {
                f = 0;
                break;
            }
        }
    else if (n == 1)
        f = 0;
    else if (n == 0)
        f = 0;
    else if (n < 0)
        f = -1;
    pthread_exit(*((void**)(&f)));
    return(NULL);
}
int main() {
    int num, rc;
    printf("Enter a number : ");
    scanf("%d", &num);

    pthread_t thread_id;
    rc = pthread_create(&thread_id, NULL, isPrime, *((void**)(&num)));
    if (rc) {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    void* f1;
    pthread_join(thread_id, &f1);
    int f = *((int*)&f1);
    if (f == 1)
        printf("Number is prime\n");
    else if (f == 0)
        printf("Number is not prime\n");
    else
        printf("Number should be non negative\n");
    pthread_exit(NULL);
    return(0);
}