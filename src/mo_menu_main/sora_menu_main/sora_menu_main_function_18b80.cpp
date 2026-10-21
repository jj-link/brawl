#pragma force_active on
struct Entry {
    char pad[0x10];
    void* value;
};

struct Entries {
    char pad[0x18C];
    Entry* entries[5];
};

struct Receiver {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void apply(void*);
};

struct Menu {
    char pad[0x64C];
    Entries* entries;
    void* unknown;
    Receiver* receiver;
};

extern "C" {
extern void* lbl_2_bss_48[2];
void exit__6gfTaskFv(void*);

void fn_2_18B80(Menu* self) {
    if (lbl_2_bss_48[0]) {
        exit__6gfTaskFv(lbl_2_bss_48[0]);
        lbl_2_bss_48[0] = 0;
    }

    for (unsigned i = 0; i < 5; ++i) {
        self->receiver->apply(self->entries->entries[i]->value);
    }
}
}
