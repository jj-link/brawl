#include <types.h>
#pragma force_active on

struct Target {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual s32 method() = 0;
};

struct Inner {
    virtual void v0() = 0;
    virtual s32* get(s32 index) = 0;
    virtual void v2() = 0;
    virtual s32 size() = 0;
};

struct Outer {
    char pad[0x2c];
    Inner* m_inner;
};

extern "C" s32 fn_27_94000(Outer* self, s32 arg1) {
    s32 i = 0;
    while (i < self->m_inner->size()) {
        if (*self->m_inner->get(i) != 0) {
            Target* obj = *(Target**)self->m_inner->get(i);
            if (arg1 == obj->method()) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
