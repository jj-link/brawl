#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE140(s16* dest, s16* src);

class Inner {
public:
    virtual void vf0();
    virtual s32 get(s32 index);
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
    virtual void apply(s32* p);
};

extern "C" {
void fn_27_1BEE50(u8* self, s16* flags, Visitor* visitor) {
    s32 count = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < count; i++) {
        s32 p = ((Inner*)(self + 0x10))->get(i);
        s16 val;
        fn_27_FE140(&val, (s16*)p);
        if (val & *flags) {
            s32 result = ((Inner*)(self + 0x10))->get(i);
            visitor->apply(&result);
        }
    }
}
}
