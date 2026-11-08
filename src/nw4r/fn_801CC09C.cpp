#pragma force_active on
struct Foo { int f0; int f4; int f8; int fC; };
extern "C" {
void* fn_801B77F8(void); void fn_801B78D4(void); void fn_8020E0EC(void); unsigned int fn_8020E18C(void); int fn_8020FD44(void); void fn_801B7FAC(int*, int); void fn_801C2C04(void); void fn_801C2CAC(void); void* fn_801BB188(void); int fn_801BB2B0(void); void fn_801BB2D8(void*, void*, unsigned int); void* fn_801D2AD0(void); int fn_801D2BCC(void); void fn_801D2BF0(void*, void*, unsigned int); void* fn_801BD6A0(void); int fn_801BD77C(void); void fn_801BD7A4(void*, int, int); void fn_801D0218(void*, int, int, unsigned int); void* fn_801CC2E4(void); void fn_801CC418(void*, int, int, int); extern char lbl_804C2010[]; extern unsigned char lbl_805A05F8;
void fn_801CC09C(void* self, int arg1) {
 Foo* p=(Foo*)self;
 if(lbl_805A05F8==0) { lbl_805A05F8=1; fn_801B77F8(); fn_801B78D4(); fn_8020E0EC(); do {} while(fn_8020E18C()==1);
 switch(fn_8020FD44()&0xFF){case 0:fn_801B7FAC((int*)fn_801B77F8(),3);break;case 1:fn_801B7FAC((int*)fn_801B77F8(),0);break;case 2:fn_801B7FAC((int*)fn_801B77F8(),2);break;default:fn_801B7FAC((int*)fn_801B77F8(),0);break;}
 fn_801C2C04(); fn_801C2CAC();
 int acc=arg1+p->fC; int base=acc; int v1; acc+=p->f4; int block=acc;
 fn_801BB188(); acc+=fn_801BB2B0(); fn_801BB188(); v1=fn_801BB2B0(); fn_801BB2D8(fn_801BB188(),(void*)block,(unsigned int)v1);
 int block2=acc; fn_801D2AD0(); acc+=fn_801D2BCC(); fn_801D2AD0(); int v2=fn_801D2BCC(); fn_801D2BF0(fn_801D2AD0(),(void*)block2,(unsigned int)v2);
 fn_801BD6A0(); fn_801BD77C(); fn_801BD6A0(); v2=fn_801BD77C(); fn_801BD7A4(fn_801BD6A0(),acc,v2);
 fn_801D0218(lbl_804C2010,p->f8,arg1,(unsigned int)p->fC); fn_801CC418(fn_801CC2E4(),p->f0,base,p->f4);
}}
}