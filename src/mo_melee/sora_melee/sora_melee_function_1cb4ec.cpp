#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Class_188F8 {
public:
    virtual void fn_27_D9F0C();
    virtual void fn_27_D9EC4();
    virtual Elem* fn_27_DAAB4(s32 index);
    virtual void fn_27_D9EE4();
    virtual void fn_27_D9EF8();
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u8 pad[0xC];
    Class_188F8 inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;
        s32 n = slot4();
        for (s32 i = 0; i < n; ++i) {
            if (key == inner.fn_27_DAAB4(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_FE000(s16* dest, s16* src);

extern "C" void fn_27_1CB4EC(s16* out, Class_18ED8* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
    } else {
        fn_27_FE000(out, (s16*)self->inner.fn_27_DAAB4(idx));
    }
}
