#pragma force_active on
#include <types.h>

struct Entry {
    s32 unknown;
    s32 id;
};

struct Array {
    virtual void unused0();
    virtual void unused1();
    virtual Entry* get(s32);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 size();

    char padding[12];
    Array array;

    s32 find(s32 id) {
        if (id <= -1)
            return -1;

        s32 count = size();
        for (s32 i = 0; i < count; ++i) {
            if (id == array.get(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_F769C(Object* self, s32 id) {
    return self->find(id) >= 0;
}
