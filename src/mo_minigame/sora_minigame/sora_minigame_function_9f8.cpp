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

struct SoOwner {
    u8 pad[0xc];
    void* m_0c;
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" {
    void* fn_802EEF18(void* p, void* arg, u32 size);
    void fn_20_9F8(SoOwner* self, void* arg);
}

extern "C" void fn_20_9F8(SoOwner* self, void* arg) {
    void* p = lbl_805A0EB8->alloc(0x2f0, 0x2d);
    *(u16*)((u8*)p + 4) = 0x2f0;
    if (p != 0) {
        p = fn_802EEF18(p, arg, 40000);
    }
    self->m_0c = p;
}
