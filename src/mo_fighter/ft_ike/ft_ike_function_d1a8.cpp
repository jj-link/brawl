#pragma force_active on
struct Module84 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void call(int, int);
};

struct Module64 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void call(int, int);
};

struct Modules {
    char pad[0x64];
    Module64* module64;
    char pad68[0x1C];
    Module84* module84;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_119_D1A8(void*, Accesser* accesser, int status) {
    switch (status) {
    case 0x11E:
    case 0x120:
        return;
    case 0x11F: {
        Module84* m = accesser->modules->module84;
        m->call(0, 0);
        break;
    }
    case 0x73: {
        Module64* m = accesser->modules->module64;
        m->call(1, 0x10000040);
    }
    default: {
        Module84* m = accesser->modules->module84;
        m->call(0, 0);
        break;
    }
    }
}
