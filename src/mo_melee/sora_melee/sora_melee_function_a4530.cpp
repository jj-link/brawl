#include <types.h>
#pragma force_active on

class ObjB {
public:
    u8 pad[0x1d];
    u8 m_flags;
};

class ObjA {
public:
    virtual void v0();
    virtual ObjB* at(s32 index);
    virtual void v2();
    virtual s32 size();
};

struct Outer {
    u8 pad[0x30];
    ObjA* m_objA;
    u8 pad2[0x14];
    s32 m_field48;
};

extern "C" void fn_27_A6C80(ObjB* obj, s32 value);

extern "C" void fn_27_A4530(Outer* self, s32 index) {
    if (index == -1) {
        s32 count = self->m_objA->size();
        for (s32 i = 0; i < count; i++) {
            u8 flag = self->m_objA->at(i)->m_flags;
            if ((flag >> 6) & 1) {
                fn_27_A6C80(self->m_objA->at(i), self->m_field48);
            }
        }
    } else {
        fn_27_A6C80(self->m_objA->at(index), self->m_field48);
    }
}
