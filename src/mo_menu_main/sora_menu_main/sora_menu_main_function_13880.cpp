#pragma force_active on
struct IFace {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void* p);
};

struct Item {
    char pad[0x10];
    void* arg;
};

struct Table {
    char pad[0x30];
    Item* items[6];
};

struct Self {
    char pad[0x64c];
    Table* table;
    unsigned int unk650;
    IFace* obj;
};

extern "C" void fn_2_13880(Self* self) {
    for (unsigned int i = 0; i < 6; i++) {
        self->obj->f13(self->table->items[i]->arg);
    }
}
