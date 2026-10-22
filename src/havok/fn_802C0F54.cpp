#pragma force_active on
typedef int s32;

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Entry {
    int unk0;
    Obj* obj;
};

struct Outer {
    virtual void v0(int flag);
    char pad[0xC - 0x4];
    Entry* entries;
    s32 count;
};

extern "C" void fn_802C0F54(Outer* self) {
    s32 i = 0;
    while (i < self->count) {
        self->entries[i].obj->v6();
        i++;
    }
    if (self != 0) {
        self->v0(1);
    }
}
