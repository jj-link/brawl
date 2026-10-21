#pragma force_active on

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
    virtual void call(void*);
};

struct Entry {
    char pad[0x10];
    void* value;
};

struct Entries {
    char pad[0x314];
    Entry* entries[4];
};

struct Container {
    char pad[0x68];
    Receiver* receiver;
    Receiver* second;
};

struct Final {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();

    char pad[0xE0];
    int value;

    virtual void apply(int, void*);
};

struct Menu {
    char pad[0x64C];
    Entries* arr;
    Container* container;
    Final* final;
};

extern "C" void fn_2_2D940(Menu* self) {
    Container* c = self->container;
    c->receiver->call(c->second);

    for (unsigned i = 0; i < 4; ++i) {
        self->container->second->call(self->arr->entries[i]->value);
    }

    self->final->apply(self->final->value, self->container->receiver);
}
