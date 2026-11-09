#pragma force_active on
extern char lbl_80490690[];
extern char lbl_804907B0[];
extern unsigned char lbl_805A49A0, lbl_805A49A1, lbl_805A49A2, lbl_805A49A3;
extern char *strchr(const char *, int);
extern void fn_8037B644(void *, unsigned char *, int);
extern void fn_8037BA34(void *, int);
extern void fn_8037BBB8(void *);
extern int fn_8037BBDC(void *);
extern int fn_8037C1C0(void *, void *, int);
typedef struct { int p0, p1, p2; int e; int f; } A;
int fn_8037FB20(A **arg0, char *arg1) {
 unsigned char buf[4];
 A *a = *arg0;
 if (a->e == 0) return 1;
 if ((*(A **)(arg1 + 0x160))->e == 0 && (*(A **)(arg1 + 0x160))->f == 0 && a->f != 0) {
 int c; char *dst; char *s = (char *)a->p2;
 buf[0]=lbl_805A49A0; buf[1]=lbl_805A49A1; buf[2]=lbl_805A49A2; buf[3]=lbl_805A49A3;
 dst=*(int *)(arg1+0x194)==0?arg1+0x54:arg1+0x78;
 while ((c=*s)!=0) {
 if(strchr(lbl_80490690,c)!=0) fn_8037BA34(dst,c);
 else if(c==0x20) fn_8037BA34(dst,0x2b);
 else {buf[1]=lbl_804907B0[c/16];buf[2]=lbl_804907B0[c%16];fn_8037B644(dst,buf,3);}
 s++;
 }
 } else return fn_8037C1C0(arg1,(void *)a->p2,a->e)!=0;
 if(*(int *)(arg1+0x194)==0) {
 if(fn_8037BBDC(arg1)==0)return 0;
 if(*(int *)(arg1+0x64)==*(int *)(arg1+0x60))fn_8037BBB8(arg1+0x54);
 return 1;
 }
 return 1;
}