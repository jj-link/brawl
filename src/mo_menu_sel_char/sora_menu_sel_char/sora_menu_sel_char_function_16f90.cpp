#pragma force_active on
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
    virtual void call(void*);
};

struct Entry {
    char pad[0x10];
    void* value;
};

struct Menu {
    char pad0[0xB0];
    Entry* entries[(0x404 - 0xB0) / 4];
    Target* target;
};

extern "C" void fn_10_16F90(Menu* self, int index) {
    self->target->call(self->entries[index]->value);
}
