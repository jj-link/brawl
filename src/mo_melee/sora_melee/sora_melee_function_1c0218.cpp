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
    virtual void apply(void** p);
};

extern "C" void fn_27_FE168(s16* dst, s16* src);

extern "C" {
void fn_27_1C0218(u8* self, s16* mask, Visitor* visitor) {
    s32 n = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < n; i++) {
        s16 val;
        fn_27_FE168(&val, (s16*)((Inner*)(self + 0x10))->get(i));
        if (val & *mask) {
            void* p = ((Inner*)(self + 0x10))->get(i);
            visitor->apply(&p);
        }
    }
}
}
