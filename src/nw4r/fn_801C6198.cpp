#pragma force_active on
#include <types.h>

class Foo {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(s32, s32, s32, s32, s32);
};

extern "C" {
void fn_801CA720(void**, void*);
void fn_801CA7E8(void**);

void fn_801C6198(Foo* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 sp8;
    sp8 = 0;
    if (arg3 != 0) {
        fn_801CA720((void**)&sp8, (void*)arg3);
    }
    arg0->v5(arg1, arg2, (s32)&sp8 & ((-arg3 | arg3) >> 0x1F), arg4, arg5);
    fn_801CA7E8((void**)&sp8);
}
}
