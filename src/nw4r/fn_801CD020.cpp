#pragma force_active on
extern "C" {
class Class_8042B6D0 { public:
virtual void fn_8004805C(); virtual void fn_8004781C(); virtual void fn_80046A28(); virtual void fn_8004810C(unsigned short*,int); virtual void fn_800480DC(); virtual void fn_801AB1C4(); virtual void fn_801B269C(); virtual void fn_801B26E4(); virtual void fn_801AAFDC(); virtual void fn_801AAFE8(); virtual void fn_801AB290(); virtual void fn_801B2EEC(); virtual void fn_801B3050(); virtual void fn_801B3248(); virtual void fn_801B3298(); virtual void fn_801B32B0(int,int);
};
struct FnArg0 { Class_8042B6D0* inner; void* field; };
int fn_801CD020(FnArg0* arg0,unsigned short* arg1,unsigned short* arg2,int arg3,int arg4) {
unsigned short buf[16] __attribute__((aligned(32)));
int x=(int)arg0->field;
if ((((unsigned)(-x|x))>>31)==0) return 0;
int off=(((unsigned)(-x|x))>>31) ? ((int*)x)[6] : 0;
off+=arg3*arg4*4+8;
arg0->inner->fn_801B32B0(off,0);
arg0->inner->fn_8004810C(buf,0x20);
for(int i=0;i<arg4;i++){arg1[i]=buf[i*2];arg2[i]=buf[i*2+1];}
return 1;
}
}