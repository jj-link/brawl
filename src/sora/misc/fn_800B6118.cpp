#include <types.h>
#pragma force_active on

struct FnP3 {
    u8 _0[0x24];
    s32 m_off;
};

struct FnP2 {
    u8 _0[0x2c];
    FnP3* m_p3;
};

struct FnP1 {
    u8 _0[0x10];
    FnP2* m_p2;
};

struct FnArg {
    u8 _0[0x14];
    FnP1* m_p1;
};

extern "C" void* fn_800B6118(FnArg* arg) {
    FnP2* p2 = arg->m_p1->m_p2;
    if (p2 == 0) {
        return 0;
    }
    FnP3* p3 = p2->m_p3;
    s32 off = p3->m_off;
    if (off != 0) {
        return (u8*)p3 + off;
    }
    return 0;
}
