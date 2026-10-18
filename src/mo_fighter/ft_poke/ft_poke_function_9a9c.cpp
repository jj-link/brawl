#pragma force_active on
struct SlotModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(bool, int, bool);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual int get(int);
};

struct WorkModule {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void onFlag(int);
};

struct Modules {
    char pad0[0x64];
    WorkModule* work;
    char pad68[0x1c];
    SlotModule* slot;
};

struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

struct Event {
    int kind;
    int pad;
    char data[1];
};

extern "C" void fn_27_377B30(Accesser*, void*);
extern "C" void fn_27_12D904(void*, bool, bool, int);
extern "C" void fn_27_1324D4(void*, Event*, Accesser*, void*, int);

extern "C" void fn_116_9A9C(
    void* self, Event* event, Accesser* accesser, void* object, int context
) {
    switch (event->kind) {
    case 0x455:
        fn_27_377B30(accesser, event->data);
        fn_27_12D904(self, true, true, 0);
        break;

    case 0x456:
        if (accesser->modules->slot->get(1) < 2) {
            accesser->modules->work->onFlag(0x22000013);
            accesser->modules->slot->set(true, 0, true);
        }
        break;
    }

    fn_27_1324D4(self, event, accesser, object, context);
}
