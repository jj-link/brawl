#pragma force_active on
struct Query {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int get(unsigned int flags);
};

struct Modules {
    char pad[0x64];
    Query* query;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_17BA0C(int, void*);
extern "C" void fn_27_17C5D8(int, void*);
extern "C" void fn_27_17C9A8(int, void*);
extern "C" void fn_27_17D3F4(int, void*);

extern "C" void fn_27_17B37C(int arg0, Owner* arg1) {
    int r;
    r = arg1->modules->query->get(0x20000000);
    switch (r) {
    case 0x2C:
        fn_27_17C5D8(arg0, arg1);
        return;
    case 0x3D:
        fn_27_17BA0C(arg0, arg1);
        return;
    case 0x18:
        fn_27_17C9A8(arg0, arg1);
        return;
    case 0xD:
        fn_27_17D3F4(arg0, arg1);
        return;
    }
}
