#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Elem* slot2(s32 index);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u32 unk4;
    u32 unk8;
    u32 unkC;
    Class_18ED8 inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;
        s32 n = slot4();
        for (s32 i = 0; i < n; ++i) {
            if (key == inner.slot2(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_FE140(s16*, s16*);

extern "C" void fn_27_1BE538(s16* out, soNullable* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
    } else {
        fn_27_FE140(out, (s16*)self->inner.slot2(idx));
    }
}