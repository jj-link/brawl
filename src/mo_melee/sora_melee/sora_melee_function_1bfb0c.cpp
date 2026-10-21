#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

struct Inner {
    virtual ~Inner();
    virtual void vf2();
    virtual Elem* get(s32 index);
    virtual void vf5();
    virtual s32 size();
};

struct Outer {
    virtual ~Outer();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
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

extern "C" s32 fn_27_1BFB0C(Outer* self, s32 key) {
    return self->find(key);
}
