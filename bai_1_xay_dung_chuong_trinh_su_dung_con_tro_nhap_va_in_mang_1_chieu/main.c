	#include <stdio.h>
	#include <stdlib.h>
	int main(){
		int n;
		printf("Nhap so phan tu:");
		scanf("%d",&n);
		if(n<=0) return 1;
		float *a=(float *)malloc(n*sizeof(float));
		if(a==NULL){
			printf("Loi cap phat bo nho");return 1;
		}
		printf("Nhap mang\n");
		int i;
		for(i=0;i<n;i++){
			printf("Nhap a[%d]: ",i);
			scanf("%f",a+i);
		}
		printf("In mang\n");
		for(i=0;i<n;i++){
			printf("%.2f\n",*(a+i));
		}
		free(a);
		return 0;
	}
