#include <types.h>
#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void dummy();
    virtual void select(int);
    virtual Entry* at(int);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();

    char padding[12];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.at(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_F7040(Object* self, int id) {
    return self->find(id);
}
