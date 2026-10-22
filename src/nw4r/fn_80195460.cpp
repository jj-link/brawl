#include <types.h>
#pragma force_active on

extern "C" u32 fn_80193E88(void* a, u32 b, u32 c);
extern "C" void fn_8019459C(void* a, void* b, u32 c, u32 d, u32 e, f32 f);
extern float lbl_805A31F0;

extern "C" void fn_80195460(u8* self, u32 a, u32 b, f32 f) {
    u32 r = fn_80193E88(self + 4, b, b + 8);
    float z;
    fn_8019459C(self + 0x1C, self + 0x10, a, b, r, f);
    z = lbl_805A31F0;
    *(u32*)self |= 0x80000000;
    *(float*)(self + 0x28) = z;
    *(float*)(self + 0x38) = z;
    *(float*)(self + 0x48) = z;
}
