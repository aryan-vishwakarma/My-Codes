#include<stdio.h>
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int *a, int low, int high)
{
    int pivot=a[high];
    int i=(low-1);
    for (int j=low;j<=high-1;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return(i+1);
}
void quickSort(int *a,int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
void inputArr(int *a,int n){
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}
void findFreq(int *a,int n,int *min,int *max){
	int k=a[0],p=0;
	int freq[n];
	*min=99999999;
	*max=0;
	freq[0]=1;
	for(int i=1;i<n;i++){
		if(a[i]==k)
		freq[p]++;
		else{
			if(freq[p]>*max)
			*max=freq[p];
			if(freq[p]<*min)
			*min=freq[p];
			k=a[i];
			freq[++p]=1;
		}
	}
    if(freq[p]>*max)
		*max=freq[p];
	if(freq[p]<*min)
		*min=freq[p];
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		int n;
		scanf("%d",&n);
		int a[n];
		inputArr(a,n);
		quickSort(a,0,n-1);
		int min,max;
		findFreq(a,n,&min,&max);
		int diff=max-min;
		if(diff)
		printf("%d\n",diff);
		else
		printf("1\n");
	}
}


