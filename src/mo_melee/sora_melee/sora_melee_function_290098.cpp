#include <types.h>
#pragma force_active on
class ResultObj { public: virtual void v0(); virtual void v1(); virtual unsigned long long v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); unsigned char pad4; unsigned char flag; };
class ModObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual ResultObj* v6(int idx); };
struct Inner { unsigned char pad[0x7C]; ModObj* mod; };
struct Outer { unsigned char pad[0xD8]; Inner* inner; };
union Bits { unsigned int i; float f; };
extern float lbl_27_rodata_46B0;
extern "C" int fn_27_290098(s32 unused, Outer* arg) {
 ResultObj* res=arg->inner->mod->v6(9); int result=0;
 int flag_bit=(((u8)res->flag >> 7U)&1);
 u32 norm=((u32)(0u-(u32)flag_bit)|(u32)flag_bit)>>31;
 if(norm==1) { unsigned long long value=res->v2(); Bits x,y; x.i=(u32)value; y.i=(u32)(value>>32); if(y.f*y.f+x.f*x.f>lbl_27_rodata_46B0) result=1; }
 if(result) return 1;
 res=arg->inner->mod->v6(7); result=0;
 flag_bit=(((u8)res->flag >> 7U)&1);
 norm=((u32)(0u-(u32)flag_bit)|(u32)flag_bit)>>31;
 if(norm==1) { unsigned long long value=res->v2(); Bits x,y; x.i=(u32)value; y.i=(u32)(value>>32); if(y.f*y.f+x.f*x.f>lbl_27_rodata_46B0) result=1; }
 return result;
}