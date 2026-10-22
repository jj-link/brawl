#include <types.h>
#pragma force_active on

extern "C" {

struct DtorObj {
    u32 m_00;
};

class GlobalAlloc {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    u32 m_04;
    u32 m_08;
    u32 m_0c;
    u32 m_10;
    u32 m_14;
    u32 m_18;
};

class HeapAlloc {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* ptr, u32 size, s32 align);
};

extern GlobalAlloc* lbl_805A0EC8;
extern HeapAlloc* lbl_805A0EB8;

DtorObj* dtor_8031F3C8(DtorObj* self, s32 flag) {
    if (self) {
        u32 vt = self->m_00;
        GlobalAlloc* g = lbl_805A0EC8;
        g->m_10 = vt;
        if (vt == g->m_18) {
            g->v4();
        }
        if (flag > 0) {
            lbl_805A0EB8->v5(self, 8, 0x15);
        }
    }
    return self;
}

}
