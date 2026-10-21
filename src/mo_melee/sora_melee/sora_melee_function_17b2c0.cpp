#pragma force_active on
struct Query {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int get(int flags);
};

struct Modules {
    char pad[0x64];
    Query* query;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void* fn_27_17B8D8(void* a, void* b);
extern "C" void* fn_27_17C5D0(void* a, void* b);
extern "C" void* fn_27_17C75C(void* a, void* b);
extern "C" void* fn_27_17D3EC(void* a, void* b);

extern "C" void fn_27_17B2C0(void* self, Owner* arg) {
    int state = arg->modules->query->get(0x20000000);
    switch (state) {
    case 0x2C:
        fn_27_17C5D0(self, arg);
        return;
    case 0x3D:
        fn_27_17B8D8(self, arg);
        return;
    case 0x18:
        fn_27_17C75C(self, arg);
        return;
    case 0xD:
        fn_27_17D3EC(self, arg);
        return;
    }
}
