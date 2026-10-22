#include <types.h>
#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

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

struct Obj {
    u32 m_00;
    u16 type;
    u16 pad;
    u32 m_08;
    void* data;
    u32 size;
    u32 raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 3, 0x15);
    }
};

extern "C" Obj* fn_802BAD90(Obj* self, int arg1) {
    if (self) {
        if ((u32)self + 0xC && (u32)self + 0xC && self->isOwned()) {
            self->dealloc();
        }
        if (arg1 > 0) {
            lbl_805A0EB8->free(self, self->type, 0x1d);
        }
    }
    return self;
}
