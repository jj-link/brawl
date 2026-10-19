#include <types.h>
#pragma force_active on

struct Elem {
    s32 m_id;
    s32 m_key;
};

class Sub {
public:
    virtual void vf0();
    virtual void setIndex(s32 index);
    virtual Elem* getElem(s32 index);
};

class Outer {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getCount();
    s32 m_unk04;
    s32 m_unk08;
    s32 m_unk0C;
    Sub m_sub;
};

static inline s32 findIndex(Outer* self, s32 key) {
    if (key <= -1) {
        return -1;
    }
    s32 count = self->getCount();
    for (s32 i = 0; i < count; i++) {
        if (self->m_sub.getElem(i)->m_key == key) {
            return i;
        }
    }
    return -1;
}

extern "C" void fn_27_F300C(Outer* self, s32 key) {
    if (key <= -1) {
        self->m_sub.setIndex(0);
        return;
    }
    s32 idx = findIndex(self, key);
    if (idx < 0) {
        self->m_sub.setIndex(0);
    } else {
        self->m_sub.setIndex(idx);
    }
}
