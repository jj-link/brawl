#include <types.h>
#pragma force_active on

struct Entry {
    s32 unused;
    s32 id;
};

struct Array {
    virtual void unused0();
    virtual void unused1();
    virtual Entry* get(s32);
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual s32 size();

    s32 padding[3];
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

extern "C" s32 fn_27_F7A24(Object* self, s32 id) {
    return self->find(id);
}
