#include <types.h>
#pragma force_active on
extern "C" {
extern const f32 lbl_27_rodata_498;
extern const f32 lbl_27_rodata_49C;
s32 fn_27_3786C(u32);
void fn_27_37A14(void*, u32);
void fn_27_37880(void*, s32, f32, f32);
void fn_27_38724(s32*);
}
struct Vec2 { f32 x; f32 y; };
class ObjList {
public:
 virtual void slot0();
 virtual s32* slot1(s32);
 virtual void slot2();
 virtual s32 slot3();
};
struct Self {
 u8 pad0[0x30];
 ObjList* m30;
 u8 pad34[4];
 f32 m38, m3C, m40, m44, m48, m4C, m50, m54, m58, m5C, m60;
 ObjList* m64;
 u8 m_sub[0x74 - 0x68];
 s32 m74;
 u8 pad78[0x10];
 s32 m88;
 f32 m8C;
 s32 m90, m94, m98;
 u32 flag0:1, flag1:1, flag2:1, flag3:1, flagRest:28;
};
inline void setup(Self* self, s32 arg1, const Vec2* v, f32 farg0) {
 f32 vx;
 f32 c49C;
 f32 vy;
 f32 c498;
 vx = v->x;
 c49C = lbl_27_rodata_49C;
 c498 = lbl_27_rodata_498;
 vy = v->y;
 self->m74 = arg1;
 self->m38 = vx;
 self->m3C = vy;
 self->m44 = c49C;
 self->m40 = c49C;
 self->m48 = c498;
 self->m4C = c49C;
 self->m50 = c49C;
 self->m54 = c498;
 self->m58 = c498;
 self->m5C = c498;
 self->m60 = farg0;
}
inline void setFlags(Self* self, s32 a) {
 self->flag1 = 0;
 self->flag3 = a;
}
extern "C" void fn_27_39AA4(Self* self, s32 arg1, const Vec2* v, u32 arg3, s32 arg4, f32 farg0, f32 farg1) {
 setup(self, arg1, v, farg0);
 self->m88 = fn_27_3786C(arg3);
 self->m8C = farg1;
 self->m90 = 0;
 self->m94 = 0;
 setFlags(self, arg4);
 self->m98 = -1;
 s32 i;
 for (i = 0; i < self->m30->slot3(); i++)
  fn_27_38724(self->m30->slot1(i));
 s32 count = self->m64->slot3();
 for (i = 0; i < count; i++)
  fn_27_37A14(self->m_sub, i);
 s32 k;
 for (k = 0; k < self->m64->slot3(); k++)
  fn_27_37880(self->m_sub, k, v->x, farg1);
}
