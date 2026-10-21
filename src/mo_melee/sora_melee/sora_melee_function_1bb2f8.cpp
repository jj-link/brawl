#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void s0();
    virtual const void* get(s32 index);
    virtual void s2();
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
    virtual void apply(const void** p);
};

extern "C" void fn_27_FE0A0(s16* a, const void* b);

extern "C" {
void fn_27_1BB2F8(u8* self, const s16* mask, Visitor* visitor) {
    s32 count = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < count; i++) {
        s16 val;
        fn_27_FE0A0(&val, ((Inner*)(self + 0x10))->get(i));
        if (val & *mask) {
            const void* p = ((Inner*)(self + 0x10))->get(i);
            visitor->apply(&p);
        }
    }
}
}
