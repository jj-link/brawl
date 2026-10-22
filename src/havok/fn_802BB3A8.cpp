#include <types.h>
#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

struct Entry {
    s32 unk0;
    Obj* obj;
};

struct Outer {
    virtual void release(s32 flag);
    virtual void v1();
    char pad[8];
    Entry* entries;
    s32 count;
};

extern "C" void fn_802BB3A8(Outer* self) {
    for (s32 i = 0; i < self->count; i++) {
        self->entries[i].obj->v6();
    }
    if (self != 0) {
        self->release(1);
    }
}
