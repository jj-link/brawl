#include <types.h>
#pragma force_active on

extern "C" char lbl_8045C768[];

struct Child {
    u8 pad[0x5C];
    virtual ~Child();
};

struct Obj {
    u8 pad0[0xC];
    Child* m_c[1];
    u8 pad10[0xC];
    void* m_1c;
};

extern "C" Obj* fn_800FD698(Obj* p, s32 flags) {
    if (p != nullptr) {
        p->m_1c = lbl_8045C768;
        for (u32 i = 0; i < 1; i++) {
            if (p->m_c[i]) {
                delete p->m_c[i];
                p->m_c[i] = nullptr;
            }
        }
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
