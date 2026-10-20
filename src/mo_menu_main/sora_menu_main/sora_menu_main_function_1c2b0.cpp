#pragma force_active on
struct Item {
    char pad[0x10];
    void* value;
};

struct Items {
    char pad[0x1B0];
    Item* entries[3];
};

class Receiver {
public:
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

struct State {
    char pad[0x64C];
    Items* items;
    char pad650[4];
    Receiver* receiver;
};

extern "C" void fn_2_1C2B0(State* self) {
    for (unsigned int i = 0; i < 3; ++i) {
        self->receiver->apply(self->items->entries[i]->value);
    }
}
