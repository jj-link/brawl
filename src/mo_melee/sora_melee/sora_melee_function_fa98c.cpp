#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

struct Object_vptr_10_base { char pad[0x10]; };
class Object_vptr_10 : public Object_vptr_10_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Elem* slot2(s32 index);
};

class Inner {
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

    char pad[0xc];
    Inner inner;

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

extern "C" void fn_27_FE1B8(s16* out, const s16* in);

extern "C" void fn_27_FA98C(s16* out, Object_vptr_0* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
    } else {
        fn_27_FE1B8(out, (const s16*)self->inner.slot2(idx));
    }
}