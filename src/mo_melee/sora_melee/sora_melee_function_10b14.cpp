#include <types.h>
#pragma force_active on

extern "C" void fn_80095B5C(void* obj, u32 flag);

class VObj {
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
    virtual int v9();
};

struct FlagBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern "C" {
void fn_27_10B14(void* p) {
    u8* self = (u8*)p;
    FlagBits* f = (FlagBits*)(self + 0x44);
    f->b0 = 0;
    if (*(void**)(self + 0x28) != 0) {
        void* o = *(void**)(self + 0x24);
        o = *(void**)((u8*)o + 0xd8);
        o = *(void**)((u8*)o + 0x44);
        u32 r = ((VObj*)o)->v9();
        if (r == 1 && f->b4) {
            fn_80095B5C(*(void**)(self + 0x28), 1);
        } else {
            fn_80095B5C(*(void**)(self + 0x28), f->b1 != 0);
        }
    }
}
}
