#include <types.h>
#pragma force_active on

class Member {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void apply(s32* p);
};

struct Outer {
    char pad[0x10];
    Member mem;
};

extern "C" void fn_27_FE140(s16* dest, s16* src);

extern "C" {
void fn_27_F8130(Outer* self, s16* flag, Visitor* visitor) {
    s16 sp8;
    s32 spC;
    s32 count = self->mem.count();
    for (s32 i = 0; i < count; i++) {
        fn_27_FE140(&sp8, (s16*)self->mem.get(i));
        if (sp8 & *flag) {
            spC = (s32)self->mem.get(i);
            visitor->apply(&spC);
        }
    }
}
}
