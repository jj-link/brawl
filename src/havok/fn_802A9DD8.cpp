#include <types.h>
#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned short, int);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern void* lbl_805A0EC8;

struct Obj {
    void* vtable;
    unsigned short f04;
    char pad06[0x2A];
    void* f30;
    int f34;
    unsigned int f38;

    unsigned int rawValue() const {
        return f38;
    }
};

extern "C" Obj* fn_802A9DD8(Obj* self, int flag) {
    if (self) {
        if ((u32)self + 0x30 &&
            (u32)self + 0x30 &&
            (u32)self + 0x30 &&
            (self->f38 & 0x80000000) == 0) {
            fn_8027EABC(lbl_805A0EC8, self->f30, self->rawValue() << 2, 0x15);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->f04, 0x1d);
        }
    }
    return self;
}
