#include <types.h>
#pragma force_active on

extern "C" void fn_8027CD94(void* a, s32 b, s32 c);

struct Fn8030ACF8_Entry {
    u16 m_key;
    u16 m_val;
};

struct Fn8030ACF8_Class {
    Fn8030ACF8_Entry* m_unk0;
    s32 m_unk4;
    u32 m_unk8;
};

extern "C" void fn_8030ACF8(Fn8030ACF8_Class* self, u16 unused, u16 arg2, u32 arg3, u32 arg4, s16* arg5, s16* arg6) {
    s32 n = self->m_unk4 + 2;
    s32 cap = self->m_unk8 & 0x3FFFFFFF;
    Fn8030ACF8_Entry* p;

    if (cap < n) {
        s32 doubled = cap * 2;
        fn_8027CD94(self, (n < doubled) ? doubled : n, 4);
    }
    self->m_unk4 = n;
    p = self->m_unk0 + (n - 3);
    while (arg4 <= p->m_key) {
        p[2] = *p;
        p--;
    }
    p[2].m_val = arg2;
    p[2].m_key = arg4;
    *arg6 = (p - self->m_unk0) + 2;
    while (arg3 < p->m_key) {
        p[1] = *p;
        p--;
    }
    p[1].m_key = arg3;
    p[1].m_val = arg2;
    *arg5 = (p - self->m_unk0) + 1;
}
