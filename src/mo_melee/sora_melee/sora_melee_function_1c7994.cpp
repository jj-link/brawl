#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE140(s16* dst, s16* src);

struct Elem {
    s32 unk0;
    s32 key;
};

class Inner {
public:
    virtual void fn_27_1B16F0();
    virtual void fn_27_1B16A8();
    virtual Elem* fn_27_1B18C8(s32 index);
};

class Outer {
public:
    virtual void fn_27_1BA390();
    virtual void fn_27_1B9D34();
    virtual void fn_27_1B9D44();
    virtual void fn_27_1A4E50();
    virtual s32 fn_27_86BA0();

    u8 pad[0xc];
    Inner inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;

        s32 n = fn_27_86BA0();
        for (s32 i = 0; i < n; i++) {
            if (key == inner.fn_27_1B18C8(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1C7994(s16* dst, Outer* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *dst = 0;
    } else {
        fn_27_FE140(dst, (s16*)self->inner.fn_27_1B18C8(idx));
    }
}