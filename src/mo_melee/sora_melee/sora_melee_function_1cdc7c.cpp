#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Elem* slot2(s32 index);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();
    u32 unk4;
    u32 unk8;
    u32 unkC;
    Object_vptr_10 inner;

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

extern "C" void fn_27_FE0C8(s16* r3, void* r4);

extern "C" void fn_27_1CDC7C(s16* out, Object_vptr_0* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0)
        *out = 0;
    else
        fn_27_FE0C8(out, self->inner.slot2(idx));
}
