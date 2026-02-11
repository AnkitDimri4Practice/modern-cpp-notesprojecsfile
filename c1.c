#include<stdio.h>
#include<stdlib.h> // bsearch function
//compare function pointer 
int compare(const void * a, const void * b){ // type unsafe
    if(*(int*)a < *(int*)b) // cast needed
    return -1;
    if(*(int*)a == *(int*)b) // cast needed
    return 0;
    if((*(int*)a > *(int*)b)) // cast needed
    return 1;
}
int main(){
    int data[]={12,3,1,4,5,6,2},k=9;
    if(bsearch(&k,data,7,sizeof(int{float}),compare))
        printf("found!\n");
    else
        printf("not found\n");
}
