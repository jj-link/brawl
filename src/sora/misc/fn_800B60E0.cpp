#include <types.h>
#pragma force_active on

struct StructD {
    u8 _0[0x14];
    s32 m_offset;
};

struct StructC {
    u8 _0[0x2C];
    StructD* m_d;
};

struct StructB {
    u8 _0[0x8];
    StructC* m_c;
};

struct StructA {
    u8 _0[0x14];
    StructB* m_b;
};

extern "C" void* fn_800B60E0(StructA* arg0) {
    StructC* c = arg0->m_b->m_c;
    if (c == 0) {
        return 0;
    }
    StructD* d = c->m_d;
    if (d->m_offset != 0) {
        return (void*)((char*)d + d->m_offset);
    }
    return 0;
}
