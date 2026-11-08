#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 a,b,c,d;} Bytes4;
extern u8 lbl_805A38E8,lbl_805A38E9,lbl_805A38EA,lbl_805A38EB;
extern int lbl_8040D420[];
extern u8 fn_8020FC24(void);
extern u16 fn_801DC318(u16);
extern void fn_801DB7E8(void *,void *,int);
void fn_801FC3A0(void) {
Bytes4 src;
Bytes4 black = {0,0,0,0};
Bytes4 dst;
Bytes4 sp8;
int var_r5;
src.a=lbl_805A38E8; src.b=lbl_805A38E9; src.c=lbl_805A38EA; src.d=lbl_805A38EB;
if(fn_8020FC24()==0) fn_801DC318(1); else fn_801DC318(0);
if(fn_8020FC24()>6) var_r5=lbl_8040D420[1]; else var_r5=lbl_8040D420[fn_8020FC24()];
sp8=black; dst=src; fn_801DB7E8(&dst,&sp8,var_r5);
}
