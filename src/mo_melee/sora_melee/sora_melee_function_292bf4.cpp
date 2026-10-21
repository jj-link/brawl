#include <types.h>
#pragma force_active on

struct Entry {
    u32 unk0;
    s32 key;
};

struct SubList {
    virtual void v0();
    virtual void v1();
    virtual Entry* getEntry(s32 idx);
};

struct Outer {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 getCount();

    u32 pad[3];
    SubList m_sub;
};

extern "C" s32 fn_27_292BF4(Outer* self, s32 key) {
    s32 result;
    if (key <= -1) {
        result = -1;
    } else {
        s32 count = self->getCount();
        result = 0;
        for (s32 i = 0; i < count; i++) {
            if (key == self->m_sub.getEntry(i)->key) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    return result;
}
