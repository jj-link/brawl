#include <types.h>
#pragma force_active on

struct SoObj {
    virtual void slot0();
    virtual SoObj* slot3(s32 index);
    u8 pad[0x5c - 4];
    s32 m_field5c;
};

struct SoHolder {
    u8 pad[4];
    s16 m_base;
    s16 m_count;
};

extern "C" void fn_27_4702C(SoHolder* holder, SoObj* obj) {
    for (s32 i = 0; i < holder->m_count; i++) {
        SoObj* r = obj->slot3(holder->m_base + i);
        r->m_field5c = 0;
    }
}
