#pragma force_active on
struct Entry {
    int a;
    int b;
};

struct Callback {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void reset();
};

struct Object {
    char pad00[0x1C];
    Entry* entries;
    int unk20;
    int count;
    char pad28[8];
    int unk30;
    unsigned char unk34;
    char pad35[3];
    int unk38;
    Callback* callback;
    char pad40[0x1C];
    int unk5c;
    int unk60;
};

extern "C" void fn_41_2A4D0(Entry*);

extern "C" void fn_41_28E64(Object* self) {
    self->unk5c = -2;
    self->unk60 = -1;
    self->callback->reset();
    self->unk30 = 0;
    self->unk34 = 0;
    self->unk38 = -1;

    for (int i = 0; i < self->count; ++i) {
        fn_41_2A4D0(&self->entries[i]);
    }
}
