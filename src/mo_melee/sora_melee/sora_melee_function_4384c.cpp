#include <types.h>
#pragma force_active on

extern "C" void fn_27_42180(s32, void*, void*, void*);

class Inner {
public:
    virtual void v0();
    virtual s32 v1(void* c);
};

class Outer {
public:
    u8 pad[0x30];
    void* m30;
    u8 pad2[0x58 - 0x34];
    Inner* m58;
};

extern "C" {
void fn_27_4384C(Outer* self, void* a, void* b, void* c) {
    fn_27_42180(self->m58->v1(c), self->m30, a, b);
}
}
