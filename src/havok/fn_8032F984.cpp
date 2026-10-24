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

struct Obj {
    void* vtable;
    u16 m04;
    u16 m06;
    void* m08;
    u32 m0c;
    u32 m10;
    void* m14;
    u32 m18;
    u32 m1c;
    u8 buffer[0x40];
    u32 m60;
    u32 m64;
    u32 m68;
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80488ED8[];
extern char lbl_80488F14[];

extern "C" {
void* fn_80331DD8(void* self);

void* fn_8032F984(void* arg0) {
    Obj* self = (Obj*)arg0;
    void* p;

    self->m06 = 1;
    self->vtable = lbl_80488ED8;
    self->m0c = 0;
    self->m10 = 0;
    self->m14 = self->buffer;
    self->m18 = 0;
    self->m1c = 0x80000010;
    self->m60 = 0;
    self->m64 = 0;
    self->m68 = 0;

    p = lbl_805A0EB8->alloc(0x48, 0x13);
    *(u16*)((u8*)p + 4) = 0x48;
    if (p != 0) {
        fn_80331DD8(p);
        *(void**)p = lbl_80488F14;
    }

    self->m08 = p;
    return arg0;
}
}
