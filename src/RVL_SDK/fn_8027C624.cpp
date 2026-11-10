#include <types.h>
#pragma force_active on

extern "C" {
void fn_8027EABC(void*, void*, unsigned int, int);
void __dt__14Class_8027D01CFv(void*, int);
}

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

struct Array {
    void* data;
    unsigned int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }
};

struct Object {
    void* vtable;
    unsigned short type;
    char pad06[0x0E];
    Array arr;
};

extern "C" Object* fn_8027C624(Object* self, int flag) {
    if (self) {
        if ((unsigned int)self + 0x14 != 0 && self->arr.isOwned()) {
            self->arr.dealloc();
        }
        if ((unsigned int)self + 8 != 0) {
            __dt__14Class_8027D01CFv((char*)self + 8, -1);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x16);
        }
    }
    return self;
}
