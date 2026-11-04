#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" void fn_16_2C20(void* self, s32 idx);
extern "C" void fn_16_32E8(void* self, u16 a, u16 b);

struct Entry {
    u16 m_0;
    s16 m_2;
};

struct Self {
    u8 m_000[0x44];
    MuObject* m_44;
    u8 m_048[0x1ec - 0x48];
    u16 m_1ec;
    u16 m_1ee;
    Entry m_1f0[0x1e8 / 4];
    u16 m_3d8;
};

extern "C" int fn_16_2B0C(void* arg0, s32 arg1) {
    Self* self = (Self*)arg0;
    Entry* e = self->m_1f0;
    u16 count = self->m_3d8;
    s16 v;
    for (s32 i = 0; i < count; e++, i++) {
        v = e->m_2;
        s32 id = (u16)(v + 2) > 1 ? v : -1;
        if (arg1 == id) {
            fn_16_2C20(arg0, i);
            fn_16_32E8(arg0, self->m_1ec, self->m_1ee);
            self->m_44->setFrameNode((float)self->m_1ec);
            MuObject* obj = self->m_44;
            s32 flags = 0;
            s32 sum = self->m_1ec + self->m_1ee;
            if (sum > 0) flags |= 2;
            if (sum < (s32)self->m_3d8 - 1) flags |= 1;
            obj->setFrameVisible((float)flags);
            return 1;
        }
    }
    return 0;
}
