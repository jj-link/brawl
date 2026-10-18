#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void target(int arg) = 0;
};

struct Entry {
    Obj* obj;
    u32 unk4;
};

struct Holder {
    u8 pad[0x40];
    Entry* entries;
};

extern "C" {
void fn_2_85CC(Holder* self, int idx, int arg) {
    self->entries[idx].obj->target(arg);
}
}
