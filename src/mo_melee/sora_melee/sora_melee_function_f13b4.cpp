#include <types.h>
#pragma force_active on

struct Entry {
    int unk0;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry& at(int);
};

struct Owner {
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual int size();

    char pad[12];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int n = size();
        for (int i = 0; i < n; i++) {
            if (id == array.at(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_F13B4(Owner* self, s32 id) {
    return ((u32)self->find(id) >> 31) ^ 1;
}
