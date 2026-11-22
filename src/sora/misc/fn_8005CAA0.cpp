#include <types.h>
#pragma force_active on
struct Object_vptr_1c_base{char pad[0x1c];};
class Object_vptr_1c:public Object_vptr_1c_base{public:virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4(int arg);};
struct Hdr{unsigned int type:8;unsigned int rest:24;};
struct Flags{u8 a:1;u8 b:1;u8 c:1;u8 d:1;u8 rest:4;};
struct FnObj{char pad0[8];void*field08;Hdr field0c;char pad10[4];f32 field14;char pad18[0x34];char sub[8];Flags fl;u8 toggle;char pad56[2];s32 frame;f32 frac;};
extern "C"{void*fn_801647B4(void);s32 fn_80164968(void*,void*,s32,s32);void fn_8016FBA0(void*,void*);s32 fn_8016FBC8(void*);void*fn_8016FBF4(void*);u32 fn_801643C8(void);void fn_8005A99C(void*);void fn_8005AA08(void*,void*);void fn_801645E8(void*,void*);void fn_801643E0(void*,void(*)(),s32,s32);void fn_80164480(void*,void(*)(),s32,s32);f64 fn_804005AC(f32);extern void fn_8005D27C(void);extern void fn_8005D34C(void);extern u32 lbl_805A0118[2];extern u32 lbl_805A0120[2];extern u32 lbl_805A0128;extern u32 lbl_805A012C;extern u32 lbl_805A0130;extern u32 lbl_805A0134;extern const f32 lbl_805A1914;}
static inline void swap_pair_a(){lbl_805A0128=lbl_805A0118[0];lbl_805A012C=lbl_805A0118[1];lbl_805A0130=lbl_805A0120[0];lbl_805A0134=lbl_805A0120[1];}
static inline void swap_pair_b(){lbl_805A0128=lbl_805A0118[1];lbl_805A012C=lbl_805A0118[0];lbl_805A0130=lbl_805A0120[1];lbl_805A0134=lbl_805A0120[0];}
extern "C" void fn_8005CAA0(FnObj*self){u8 matrix[0x30];f32 temp_f0_2;f32 temp_f0;f32 var_f2;u32 i;void*next;void*handle;s32 n;
if(self->fl.b){void*mgr=fn_801647B4();s32 r=fn_80164968(mgr,self->field08,0,0);if(r!=0)fn_8016FBA0(self->sub,(void*)r);self->fl.b=0;}
if(fn_8016FBC8(self->sub)!=0){handle=fn_8016FBF4(self->sub);if(fn_801643C8()==0){self->field0c.type=3;if(self->fl.a)fn_8005A99C(self);}else{fn_8005AA08(self,matrix);fn_801645E8(handle,matrix);}
var_f2=(f32)fn_804005AC(self->field14);temp_f0=self->field14;
if(var_f2<temp_f0){temp_f0=temp_f0-var_f2;self->fl.c=1;temp_f0_2=lbl_805A1914;var_f2=temp_f0_2+var_f2;self->frac=temp_f0;}
else{f32 one=lbl_805A1914;self->fl.c=0;self->frac=one;}
n=(s32)var_f2-self->frame;
if(n>=1){if(!(self->toggle&1))swap_pair_a();else swap_pair_b();self->fl.d=0;
if(n>1){i=0;while(i<(u32)(n-1)){((Object_vptr_1c*)handle)->slot4(0);i++;}self->toggle=(u8)((self->toggle^1)&1);self->fl.d=1;next=fn_8016FBF4(self->sub);if(self->fl.d){if(!(self->toggle&1))swap_pair_a();else swap_pair_b();self->fl.d=0;}fn_801643E0(next,fn_8005D27C,2,1);fn_80164480(next,fn_8005D34C,2,1);}
((Object_vptr_1c*)handle)->slot4(0);self->frame+=n;self->toggle=(u8)((self->toggle^1)&1);self->fl.d=1;next=fn_8016FBF4(self->sub);if(self->fl.d){if(!(self->toggle&1))swap_pair_a();else swap_pair_b();self->fl.d=0;}fn_801643E0(next,fn_8005D27C,2,1);fn_80164480(next,fn_8005D34C,2,1);}
}else{self->field0c.type=3;if(self->fl.a)fn_8005A99C(self);}}
