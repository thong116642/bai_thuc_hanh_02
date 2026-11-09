#include <stdio.h>
#include <stdlib.h>

struct SinhVien{
	char hoten[30];
	int masv;
	float diem1,diem2,diem3;
};

struct Node{
	struct SinhVien data;
	struct Node *link;
};

struct LList{
	struct Node *pHead;
	struct Node *pTail;
	int spt;
};

void initList(struct LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

int isEmpty(struct LList L){
	return L.spt == 0;
}

void Nhap(struct SinhVien *sv){
	printf("Ho ten: ");
    scanf(" %[^\n]", sv->hoten);
    printf("Ma sinh vien: ");
    scanf("%d", &sv->masv);
    printf("Diem 1: ");
    scanf("%f", &sv->diem1);
    printf("Diem 2: ");
    scanf("%f", &sv->diem2);
    printf("Diem 3: ");
    scanf("%f", &sv->diem3);
}

void Xuat(struct SinhVien sv){
    printf("Ho ten: %s\tMa sv: %d\tDiem 1: %.2f\tDiem 2: %.2f\tDiem 3: %.2f\n",  sv.hoten, sv.masv, sv.diem1, sv.diem2, sv.diem3);
}

void insertHead(struct LList *L, struct SinhVien sv){
	struct Node *pp;
	pp = (struct Node*)malloc(sizeof(struct Node));
	if(pp == NULL){
		printf("Khong du bo nho");
		return;
	}
	pp->data = sv;
	pp->link = L->pHead;
	if(isEmpty(*L)){
		L->pTail = pp;
	}
	L->pHead = pp;
	L->spt++;
}

void insertTail(struct LList *L, struct SinhVien sv) {
    struct Node *pp;
    pp = (struct Node*)malloc(sizeof(struct Node));
    if (pp == NULL) {
        printf("Khong du bo nho");
        return;
    }
    pp->data = sv;
    pp->link = NULL;
    if (isEmpty(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}

struct Node *findNode(struct LList L, int ma) {
    struct Node *q = L.pHead;
    while (q != NULL && q->data.masv != ma){
    	q = q->link;
	}
    return q;
}

void insertAfter(struct LList *L, int ma, struct SinhVien x) {
    struct Node *q = findNode(*L, ma);
    if (q == NULL) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }
    struct Node *pp = (struct Node*)malloc(sizeof(struct Node));
    if (pp == NULL) return;
    pp->data = x;
    pp->link = q->link;
    q->link = pp;
    if (q == L->pTail){
    	L->pTail = pp;
	}
    L->spt++;
}

void processList(struct LList L) {
    struct Node *pp = L.pHead;
    if (isEmpty(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    while (pp != NULL) {
        Xuat(pp->data);
        pp = pp->link;
    }
}

void freeList(struct LList *L) {
    struct Node *pp;
    while (L->pHead != NULL) {
        pp = L->pHead;
        L->pHead = L->pHead->link;
        free(pp);
    }
    L->pTail = NULL;
    L->spt = 0;
}

int main() {
    struct LList L;
    struct SinhVien x;
    int chon;
    int ma;
    initList(&L);
    do {
        printf("\n===== QUAN LY SINH VIEN =====\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3: Them vao sau mot nut khac\n");
        printf("4: Tim kiem sinh vien\n");
        printf("9. Duyet danh sach\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                Nhap(&x);
                if (x.masv > 0) {
                    insertHead(&L, x);
                }
                break;
            case 2:
                Nhap(&x);
                if (x.masv > 0) {
                    insertTail(&L, x);
                }
                break;
            case 3:
                printf("Nhap ma sinh vien can chen sau: ");
                scanf("%d", &ma);
                printf("Nhap thong tin sinh vien moi:\n");
                Nhap(&x);
                if (x.masv > 0) {
                    insertAfter(&L, ma, x);
                }
                break;
            case 4: {
			    printf("Nhap ma sinh vien can tim: ");
			    scanf("%d", &ma);
			
			    struct Node *q = findNode(L, ma);
			
			    if (q == NULL) {
			        printf("Khong tim thay sinh vien!\n");
			        break;
			    }
			
			    Xuat(q->data);
			    break;
			}
            case 9:
                processList(L);
                break;
            case 0:
                printf("Bye bye!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);
    freeList(&L);
    return 0;
}
