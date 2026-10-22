#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(u32 size, s32 align);
};

struct SoObj {
    void* m_00;
    void* m_04;
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" {
    void* fn_802E2840(void* p, void* arg);
    extern char lbl_80454A90[];
}

extern "C" SoObj* fn_80095FC4(SoObj* self, void* arg) {
    void* p;
    self->m_04 = lbl_80454A90;
    self->m_00 = 0;
    p = lbl_805A0EB8->alloc(0x1f0, 0x2b);
    *(u16*)((u8*)p + 4) = 0x1f0;
    if (p != 0) {
        p = fn_802E2840(p, arg);
    }
    self->m_00 = p;
    return self;
}
