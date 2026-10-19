#include <types.h>
#pragma force_active on

extern "C" void fn_27_A7638(void* a, u32 b);

class Inner {
public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
};

struct Outer {
    char pad[0x30];
    Inner* m30;
};

extern "C" void fn_27_A4644(Outer* self, void* a, u32 c) {
    fn_27_A7638(self->m30->v1(), c);
}
