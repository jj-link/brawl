#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Holder {
    char pad[0x10];
    Inner *inner;
};

struct Owner {
    char pad[0x48];
    Holder **table;
};

extern "C" void fn_70_4818(Owner *self, int idx)
{
    Holder *h;
    if (self->table[idx] == 0) {
        return;
    }
    h = self->table[idx];
    if (h->inner == 0) {
        return;
    }
    h->inner->v5();
}
