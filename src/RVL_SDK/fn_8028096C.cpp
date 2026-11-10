#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual ~Inner();
    unsigned short active;
    short refs;
};

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
extern char lbl_80486450[];

class Class_8028096C {
public:
    void* vtable;
    unsigned short type;
    Inner* inner;
};

extern "C" Class_8028096C* __dt__14Class_8028096CFv(Class_8028096C* self, int flag) {
    if (self != 0) {
        Inner* inner = self->inner;
        self->vtable = lbl_80486450;
        if (inner != 0 && inner->active != 0) {
            inner->refs -= 1;
            if (inner->refs == 0) {
                delete inner;
            }
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x18);
        }
    }
    return self;
}
