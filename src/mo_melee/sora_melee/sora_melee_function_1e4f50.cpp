#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Elem* get(s32 index);
    virtual void vf3();
    virtual void vf4();
};

class Outer {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 count();

    u32 unk4;
    u32 unk8;
    u32 unkC;
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

extern "C" void fn_27_FE1E0(s16* a, const void* b);

extern "C" void fn_27_1E4F50(s16* out, Outer* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
    } else {
        fn_27_FE1E0(out, self->m_inner.get(idx));
    }
}