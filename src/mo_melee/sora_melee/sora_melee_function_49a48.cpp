#include <types.h>
#pragma force_active on

struct SoHolder {
    u8 pad[4];
    s16 m_base;
    s16 m_count;
};

struct SoObj {
    virtual void slot0();
    virtual SoObj* slot3(s32 index);
    u8 pad[0x5c - 4];
    s32 m_field5c;
};

struct ArrayLike {
    virtual void v0();
    virtual SoHolder* at(s32 index);
    virtual void v1();
    virtual s32 size();
};

struct OuterObj {
    u8 pad[0x20];
    SoObj* m_obj;
    u8 pad24[0x24];
    ArrayLike* m_array;
};

extern "C" void fn_27_4702C(SoHolder* holder, SoObj* obj);

extern "C" void fn_27_49A48(OuterObj* self) {
    s32 count = self->m_array->size();
    for (s32 i = 0; i < count; i++) {
        fn_27_4702C(self->m_array->at(i), self->m_obj);
    }
}
