#include <types.h>
#pragma force_active on

struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(s32 arg);
};

struct Entry {
    int pad;
    Obj* obj;
};

struct Self {
    u8 pad[0xfc];
    Entry* entries;
    u8 count;
};

extern "C" void fn_80183228(void* self, s32 arg);

extern "C" void fn_80185EA4(Self* self, s32 arg) {
    int off = 0;
    for (s32 n = 0; n < (s32)self->count; n++) {
        Entry* e = (Entry*)((char*)self->entries + off);
        e->obj->slot3(arg);
        off += 8;
    }
    fn_80183228(self, arg);
}
