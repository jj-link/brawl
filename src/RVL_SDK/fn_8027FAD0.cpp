#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void* s4(s32, s32, s32, s32);
    unsigned char pad[0x28];
    s32 count;
};

struct Rec {
    unsigned char pad[0x30];
    u8 flag;
    s32 a;
    void* b;
    s32 c;
    u8 d;
};

extern "C" void fn_8027FAD0(Obj* self, s32 a, s32 b) {
    s32 count = self->count;
    s32 offset = count * 0x14;
    self->count = count + 1;
    Rec* r = (Rec*)((char*)self + offset);
    r->flag = 1;
    r->a = a;
    r->b = self->s4(a, b, offset, count + 1);
    r->c = b;
    r->d = 0;
}