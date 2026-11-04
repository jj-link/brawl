#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE028(s16* dst, const s16* src);

struct Elem {
    s32 unk0;
    s32 key;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Elem* get(s32 index);
};

class Outer {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 count();

    u8 pad[0xC];
    Inner m_inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;

        s32 n = count();
        for (s32 i = 0; i < n; ++i) {
            if (key == m_inner.get(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1C9740(s16* out, Outer* self, s32 key) {
    s32 idx = self->find(key);

    if (idx < 0) {
        *out = 0;
    } else {
        fn_27_FE028(out, (const s16*)self->m_inner.get(idx));
    }
}