#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Inner {
public:
    virtual void fn_27_AC9D8();
    virtual void fn_27_AC37C();
    virtual Elem* fn_27_AC38C(s32);
};

class Container {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 getCount();

    s32 pad[3];
    Inner inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;

        s32 count = getCount();
        for (s32 i = 0; i < count; ++i) {
            if (key == inner.fn_27_AC38C(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_FE078(s16* a, Elem* b);

extern "C" void fn_27_F3CC0(s16* out, Container* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
        return;
    }
    fn_27_FE078(out, self->inner.fn_27_AC38C(idx));
}
