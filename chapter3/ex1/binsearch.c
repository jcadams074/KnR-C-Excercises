/*
Our binary search makes two tests inside the loop, when only one would suffice
(at the price of more tests outside). Write a vesrion with only one test inside
the loop and measure the runtime.
*/

#include <stdio.h>
#include <time.h>

#define SIZE 100000

int ogBinsearch(int x, int v[], int n);
int newBinsearch(int x, int v[], int n);

int main(){

    int x = 830;
    int v[SIZE];

    for (int i = 0; i < SIZE; i++) {
        v[i] = i;
    }

    int n = 100000;

    clock_t ogBegin = clock();
    ogBinsearch(x,v,n);
    clock_t ogEnd = clock();

    clock_t newBegin = clock();
    newBinsearch(x,v,n);
    clock_t newEnd = clock();

    double ogRuntime = (double)(ogEnd - ogBegin)/ CLOCKS_PER_SEC;
    double newRuntime = (double)(newEnd - newBegin)/ CLOCKS_PER_SEC;

    printf("OG Binsearch CPU Runtime -> %0.80f\n", ogRuntime);
    printf("New Binsearch CPU Runtime -> %0.80f\n", newRuntime);

    //Runtime is exactly the same

    return 0;
}


int ogBinsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low+high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int newBinsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low+high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

    }

    if(x == v[mid])
        return mid;
    else
        return -1;
}


