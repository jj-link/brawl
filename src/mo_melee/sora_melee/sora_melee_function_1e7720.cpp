#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE168(s16* dst, s16* src);

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
    virtual s32 getCount();

    u8 pad[0xC];
    Inner m_inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = getCount();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == m_inner.get(idx)->key)
                return idx;
        }
        return -1;
    }
};

extern "C" void fn_27_1E7720(s16* dst, Outer* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *dst = 0;
        return;
    }
    fn_27_FE168(dst, (s16*)self->m_inner.get(idx));
}
