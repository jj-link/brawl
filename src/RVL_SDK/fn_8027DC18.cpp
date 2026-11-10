#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(u32 a, u32 b);
};

extern Object_vptr_0* lbl_805A0EB8;

extern "C" {
void fn_80281D64(void* a, int b, int c);

void* fn_8027DC18(void* arg0) {
    void* block = lbl_805A0EB8->slot4(0xC0, 0x15);
    *(void**)arg0 = block;
    fn_80281D64(block, 0xFF, 0x40);
    *(u32*)((char*)arg0 + 4) = 0;
    *(u32*)((char*)arg0 + 8) = 0xF;
    return arg0;
}
}
