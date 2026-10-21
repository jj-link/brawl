#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0() = 0;
    virtual void* get(s32 index) = 0;
    virtual void vf2() = 0;
    virtual s32 count() = 0;
};

class Visitor {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void apply(void** p) = 0;
};

extern "C" void fn_27_FE140(short *dest, short *src);

extern "C" {
void fn_27_1CE594(u8* self, s16* flags, Visitor* visitor) {
    s32 n = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < n; i++) {
        s16 val;
        fn_27_FE140(&val, (s16*)((Inner*)(self + 0x10))->get(i));
        if (val & *flags) {
            void* item = ((Inner*)(self + 0x10))->get(i);
            visitor->apply(&item);
        }
    }
}
}
