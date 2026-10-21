#include <types.h>
#pragma force_active on

class Elem {
public:
    s32 m_pad;
    s32 m_key;
};

class Lister {
public:
    virtual void v0();
    virtual void v1();
    virtual Elem* getElem(s32 idx);
};

class Container {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 getCount();

    s32 m_unk[3];
    Lister m_lister;
};

inline s32 find(Container* self, s32 key) {
    if (key <= -1)
        return -1;

    s32 count = self->getCount();
    for (s32 i = 0; i < count; ++i) {
        if (key == self->m_lister.getElem(i)->m_key)
            return i;
    }
    return -1;
}

extern "C" s32 fn_27_1CF250(Container* self, s32 key) {
    return find(self, key);
}
