#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 idx);
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

struct Obj {
    void* pad[4];
    Inner inner;
};

extern "C" {
void fn_27_FDFD8(void* a, const void* b);

void fn_27_1CA058(Obj* self, s16* flags, Visitor* visitor) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        void* p = self->inner.get(i);
        s16 flag;
        fn_27_FDFD8(&flag, p);
        if (flag & *flags) {
            void* p2 = self->inner.get(i);
            visitor->apply(&p2);
        }
    }
}
}
