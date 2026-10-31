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
};

struct Entry {
    char pad[0x18];
    Obj *obj;
};

struct Owner {
    char pad[0x48];
    Entry **table;
};

extern "C" {
void fn_46_6174(Owner *self, int idx) {
    Entry *e = self->table[idx];
    if (e == 0) {
        return;
    }
    e->obj->v5();
}
}
