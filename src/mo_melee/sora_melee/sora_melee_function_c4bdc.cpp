#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 index);
    virtual void vf2();
    virtual s32 count();
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
    virtual void vf10(void** p);
};

extern "C" {
void fn_27_C5AA8(s16* a, s16* b);

void fn_27_C4BDC(u8* self, s16* flag, Visitor* visitor) {
    s16 sp8;
    void* spC;
    s32 n = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < n; i++) {
        s16* p = (s16*)((Inner*)(self + 0x10))->get(i);
        fn_27_C5AA8(&sp8, p);
        if (sp8 & *flag) {
            spC = (void*)((Inner*)(self + 0x10))->get(i);
            visitor->vf10(&spC);
        }
    }
}
}
