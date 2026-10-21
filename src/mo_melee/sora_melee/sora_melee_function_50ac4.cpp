#include <types.h>
#pragma force_active on

extern "C" void fn_27_54218(s16* dst, const void* src);

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 index);
    virtual void vf2();
    virtual s32 count();
};

class Outer {
    char pad[0x10];
public:
    Inner inner;
};

class Sink {
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

extern "C" void fn_27_50AC4(Outer* self, s16* flags, Sink* sink) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        void* p = self->inner.get(i);
        s16 val;
        fn_27_54218(&val, p);
        if (val & *flags) {
            s32 data = (s32)self->inner.get(i);
            sink->apply(&data);
        }
    }
}
