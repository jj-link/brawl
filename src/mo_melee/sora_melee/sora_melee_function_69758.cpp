#include <types.h>
#pragma force_active on

struct FooObj {
    u8 pad_00[0x20];
    void* m_20;
    u32 m_24;
    float m_28;
    u8 pad_2c[0x34 - 0x2C];
    u8 a : 3;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 2;
};

extern "C" {
void fn_27_69758(FooObj* p, void* a, u32 b, u32 c, float f) {
    p->m_20 = a;
    p->m_24 = 0;
    p->m_28 = f;
    p->a = 1;
    p->b = b;
    p->c = 0;
    p->d = c;
}
}
