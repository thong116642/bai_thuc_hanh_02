	#include <stdio.h>
	#include <stdlib.h>
		typedef struct {
			char hoten[30];
			int masv;
			float d1,d2,d3;
		}SV;
		void nhap(SV *a){
			printf("Nhap ma sv: ");
			scanf("%d",&(a->masv));
			if(a->masv>0){
				printf("Nhap ho ten: ");
				fflush(stdin);
				scanf("%[^\n]",a->hoten);
				printf("Nhap diem mon 1: ");
				scanf("%f",&(a->d1));
				printf("Nhap diem mon 2: ");
				scanf("%f",&(a->d2));
				printf("Nhap diem mon 3: ");
				scanf("%f",&(a->d3));
			}
		}
		void in(const SV *a){
			printf("Ten: %s,MaSV: %d,Diem 1: %.2f,Diem 2: %.2f,Diem 3: %.2f\n",a->hoten,a->masv,a->d1,a->d2,a->d3);
		}
	int main(){
		int n,i;
		printf("Nhap so luong sinh vien: ");
		scanf("%d",&n);
		if(n<=0){
			printf("So sinh vien ko hop le\n");return 1;
		}
		SV *ds=(SV *)malloc(n*sizeof(SV));
		if(ds==NULL){
			printf("Loi cap phat bo nho\n");return 1;
		}
		printf("Nhap danh sach sv:\n");
		for(i=0;i<n;i++){
			printf("Nhap sinh vien thu %d:\n",i+1);
			nhap(ds+i);
		}
		printf("Danh sach sinh vien da nhap\n");
		for(i=0;i<n;i++){
			in(ds+i);
		}
		free(ds);
		ds=NULL;
		return 0;
	}
