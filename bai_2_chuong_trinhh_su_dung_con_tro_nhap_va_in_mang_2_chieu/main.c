	#include <stdio.h>
	#include <stdlib.h>
	int main(){
		int h,c;
		printf("Nhap so hang va so cot: ");
		scanf("%d%d",&h,&c);
		float **ma=(float **)malloc(h*sizeof(float *));
		if(ma==NULL){
			printf("Khong du bo nho!\n");
			return 1;
		}
		int i;int j;
		for(i=0;i<h;i++){
			ma[i]=(float *)malloc(c*sizeof(float));
			if(ma[i]==NULL){
				printf("Khong du bo nho tai dong %d!\n",i);
				return 1;
			}
		}
		for(i=0;i<h;i++){
			for(j=0;j<c;j++){
				scanf("%f",&ma[i][j]);
			}
		}
		printf("Ma tran %dx%d vua tao:\n",h,c);
		for(i=0;i<h;i++){
			for(j=0;j<c;j++){
				printf("%.2f\t",ma[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<h;i++){
			free(ma[i]);
		}
		free(ma);
		return 0;
	}
