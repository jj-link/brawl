#include <types.h>
#pragma force_active on

struct Entry {
    u8 flags;
    u8 pad;
    s16 id;
    int unused;
    int value;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Entry* slot1(int index);
    virtual void slot2();
    virtual int slot3();
};

struct Owner {
    char pad[12];
    Object_vptr_0* object;
};

extern "C" void fn_27_AB41C(s16*, const Entry*);
extern "C" unsigned int fn_27_775AC(Entry*, void*, unsigned int*, int);

extern "C" int fn_27_AB2F4(Owner* self, void* arg1, int* arg2, int* arg3, unsigned int* arg4, s16* arg5, int arg6, Entry* entry, int i) {
    *arg2 = 0;
    *arg3 = -1;
    Object_vptr_0* object = self->object;
    int count = object->slot3();
    for (i = 0; i < count; i++) {
        entry = object->slot1(i);
        int skip = 0;
        if (*arg5 != 0) {
            s16 flag;
            fn_27_AB41C(&flag, entry);
            if (!(flag & *arg5)) {
                skip = 1;
            }
        }
        if (skip == 0) {
            unsigned int result = 0;
            if (((entry->flags >> 7) & 1) && fn_27_775AC(entry, arg1, &result, arg6) == 1) {
                *arg2 = entry->id;
                *arg3 = entry->value;
                *arg4 = result;
                return 1;
            }
        }
    }
    return 0;
}
