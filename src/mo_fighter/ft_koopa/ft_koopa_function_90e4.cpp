#include <stddef.h>
#pragma force_active on

class Hdr {
public:
    unsigned int h0;
    unsigned int h1;
};

class Obj : public Hdr {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20(unsigned int a, unsigned int b);
    virtual void vf21();
    virtual unsigned int vf22();
};

extern "C" unsigned int fn_102_90E4(Obj* self, unsigned int a, unsigned int b) {
    unsigned int result = self->vf22();
    if (result == 1) {
        self->vf20(a, b);
    }
    return result;
}
