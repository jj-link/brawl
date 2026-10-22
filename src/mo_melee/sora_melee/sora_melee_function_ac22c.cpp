#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v1() = 0;
    virtual s32 get(s32 index) = 0;
    virtual void v3() = 0;
    virtual s32 size() = 0;
};

struct Outer {
    char pad[8];
    Inner* m_inner;
};

struct Target {
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void set(s32* p) = 0;
};

extern "C" void fn_27_AC22C(Outer* self, Target* arg1) {
    s32 value;
    for (s32 i = 0; i < self->m_inner->size(); i++) {
        value = self->m_inner->get(i);
        arg1->set(&value);
    }
}
