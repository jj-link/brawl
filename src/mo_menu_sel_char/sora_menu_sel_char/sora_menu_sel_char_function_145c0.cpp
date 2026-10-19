#pragma force_active on
struct Item {
    char pad[0x10];
    void* value;
};

struct Manager {
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
    virtual void target(void*, void*);

    char pad[0xE4 - 4];
    void* arg;
};

struct Object {
    char pad[0xAC];
    Manager* manager;
    Item* items[1];
};

extern "C" void fn_10_145C0(Object* self, unsigned index) {
    Manager* manager = self->manager;
    manager->target(manager->arg, self->items[index]->value);
}
