#pragma force_active on
struct Entry {
    char pad[0x10];
    int handle;
};

struct Manager {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34(int, int);
    virtual void v38();
    virtual void v3C(int);

    char pad[0xE0];
    int value;
};

struct Object {
    char pad0[0xBC];
    Entry* first;
    Entry* second;
    char pad1[0x2B4 - 0xC4];
    int index;
    int value;
    char pad2[0x350 - 0x2BC];
    unsigned char enabled;
};

extern Manager* lbl_805A02E0;

extern "C" void fn_8002577C(int, unsigned char);
extern "C" void fn_800257B0(int, int);

extern "C" void fn_800E4D28(Object* self, int enabled) {
    Entry* first = self->first;
    Entry* second = self->second;

    lbl_805A02E0->v3C(first->handle);
    lbl_805A02E0->v3C(second->handle);

    int value;
    if (enabled) {
        lbl_805A02E0->v34(lbl_805A02E0->value, first->handle);
        lbl_805A02E0->v34(lbl_805A02E0->value, second->handle);
        value = self->value;
    } else {
        value = 0;
    }

    fn_8002577C((unsigned char)self->index, value != 0);
    fn_800257B0((unsigned char)self->index, value);
    self->enabled = enabled;
}
