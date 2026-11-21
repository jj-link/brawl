#include <ft/ft_common_data_accesser.h>
#pragma force_active on
struct Class_1768_base { char pad[12]; };
class Class_1768 : public Class_1768_base { public:
virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void fn_27_1D37C(int,int,int); };
struct TaskProxy_base { char pad[60]; };
class TaskProxy : public TaskProxy_base { public:
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual unsigned int slot40(); };
struct Access { char pad[8]; TaskProxy* fighter; };
extern "C" unsigned int* fn_27_14554C(void*,unsigned int,unsigned int);
extern "C" void fn_27_1D6434(int,int,int,Class_1768*,Access*);
extern "C" void fn_27_1D61CC(int a,int b,int unused,Access* access,Class_1768* out) {
unsigned int* p=fn_27_14554C(&g_ftCommonDataAccesser,access->fighter->slot40(),a);
unsigned int* q=fn_27_14554C(&g_ftCommonDataAccesser,access->fighter->slot40(),b);
unsigned int x=*p,y=*q; unsigned int x20=(x>>6)&0xfffff; unsigned int y20=(y>>6)&0xfffff;
int type=x20&15; int oldtype=y20&15; unsigned char id=(unsigned char)(x20>>4);
if(type==2) { unsigned int special; unsigned char yid=(unsigned char)(y20>>4); special=(x20&0x1000)>>12;
if((int)id==0x3d) { if(!(oldtype==2&&(int)yid==0x3d&&special!=1)) out->fn_27_1D37C(1,0x15,0); } }
else if(type==6) out->fn_27_1D37C(1,0x15,0);
if(oldtype!=3&&type==3) out->fn_27_1D37C(1,0x16,0);
if(oldtype!=5&&type==5) out->fn_27_1D37C(1,0x1a,0);
int bit=(*p>>18)&1; fn_27_1D6434(type,id,bit,out,access);
if(((*p>>22)&1)&&(!((*q>>22)&1)||bit)) out->fn_27_1D37C(1,0x1d,0);
if(((*p>>23)&1)&&(!((*q>>23)&1)||bit)) out->fn_27_1D37C(1,0x19,0);
if(((*p>>24)&1)&&(!((*q>>24)&1)||bit)) out->fn_27_1D37C(1,0x1b,0);
}