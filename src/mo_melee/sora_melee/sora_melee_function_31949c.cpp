#include <types.h>
#pragma force_active on
struct Entry {
    int unused0;
    int unused1;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry* at(int);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();

    int pad[3];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int n = size();
        for (int i = 0; i < n; ++i) {
            if (id == array.at(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_31949C(Object* self, s32 id) {
    s32 index = self->find(id);
    return index >= 0;
}
