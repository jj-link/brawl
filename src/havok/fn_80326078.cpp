#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(void* p, u16 size, s32 arg);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void dtor_80326078(void* self) {
    lbl_805A0EB8->vf5(self, *(u16*)((u8*)self + 4), 0x13);
}
