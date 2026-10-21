#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void* alloc(u32 size, s32 align);
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* p, u32 size, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct SoBlockHeader {
    u8 pad[0x4];
    u16 size;
};

extern "C" {
void dtor_8030A6BC(void* p) {
    SoBlockHeader* h = (SoBlockHeader*)p;
    lbl_805A0EB8->free(p, h->size, 0x1f);
}
}
