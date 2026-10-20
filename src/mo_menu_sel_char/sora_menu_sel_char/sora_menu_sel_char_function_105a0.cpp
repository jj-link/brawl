#pragma force_active on
extern "C" const unsigned int lbl_10_rodata_518[2];

struct Target {
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
    virtual void invoke(void*);
};

struct Entry {
    char pad[0x10];
    void* value;
};

struct Menu {
    char pad[0x13c];
    Entry* entries[0xf3];
    Target* target;
};

extern "C" void fn_10_105A0(Menu* self, unsigned int index) {
    Target* target = self->target;
    target->invoke(self->entries[lbl_10_rodata_518[index]]->value);
}
