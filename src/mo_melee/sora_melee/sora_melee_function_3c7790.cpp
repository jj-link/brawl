#include <types.h>
#pragma force_active on
extern const f32 lbl_27_rodata_8088;
extern const f32 lbl_27_rodata_808C;
class IA {
public:
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
virtual f32 v12(u32)=0; virtual void v13(u32,f32)=0;
virtual void v14()=0; virtual void v15()=0; virtual void v16()=0;
virtual void v17(f32*,s16*)=0; virtual void v18(f32*,s16*)=0;
};
struct Locals { s16 b,pad0,a,pad1; f32 v[4]; };
inline void initialize(Locals& L) { L.v[0]=lbl_27_rodata_808C; L.v[1]=lbl_27_rodata_8088; L.v[2]=lbl_27_rodata_8088; L.a=1; }
extern "C" void fn_27_3C7790(u8* p) {
Locals L;
IA* o=*(IA**)(*(u8**)(p+0xd8)+0x64);
u32 base=0x21000000;
initialize(L);
(*(IA**)(*(u8**)(p+0xd8)+0x7c))->v17(L.v,&L.a);
L.b=1;
(*(IA**)(*(u8**)(p+0xd8)+0x7c))->v18(L.v,&L.b);
o->v13(base+4,-o->v12(base+4));
o->v13(base+6,-o->v12(base+6));
o->v13(base+7,-o->v12(base+7));
o->v13(base+8,-o->v12(base+8));
o->v13(base+9,-o->v12(base+9));
o->v13(base+10,-o->v12(base+10));
o->v13(base+11,-o->v12(base+11));
}
