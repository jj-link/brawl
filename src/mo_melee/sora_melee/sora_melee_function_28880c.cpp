#include <types.h>
#pragma force_active on
extern const float lbl_27_rodata_4610;
class SoraIfaceB {
public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v6(s32 n, void* p, float f);
 virtual void v7();
 virtual void v8(float f, s32 n, void* p, s32 flag);
};
struct SoraMeleeFn27 {
 u8 m_pad0[0x33d0];
 SoraIfaceB m_b;
};
extern "C" void fn_27_28880C(SoraMeleeFn27* self, s32 x) {
 self->m_b.v8(lbl_27_rodata_4610, 5, (void*)&self->m_pad0[0xcc], x);
 self->m_b.v6(5, (void*)&self->m_pad0[0xcc], (float)x);
}
