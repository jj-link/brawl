#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 idx);
    virtual void vf2();
    virtual s32 vf3();
};

class Visitor {
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
    virtual void vf10(s32* p);
};

extern "C" {
void fn_27_1CF51C(s16* dest, s16* src);

void fn_27_1C338C(u8* self, s16* arg1, Visitor* arg2) {
    s32 spC;
    s16 sp8;
    s32 count = ((Inner*)(self + 0x10))->vf3();
    for (s32 i = 0; i < count; i++) {
        fn_27_1CF51C(&sp8, (s16*)((Inner*)(self + 0x10))->vf1(i));
        if (sp8 & *arg1) {
            spC = (s32)((Inner*)(self + 0x10))->vf1(i);
            arg2->vf10(&spC);
        }
    }
}
}
