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
    virtual Elem* get(s32 index);
};

class Outer {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual s32 count();

    s32 pad[3];
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

extern "C" void fn_27_FE0A0(s16* a, const void* b);

extern "C" void fn_27_264404(s16* out, Outer* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
        return;
    }
    fn_27_FE0A0(out, self->m_inner.get(idx));
}
