#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int);
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
    virtual int slot16(int);
};

struct Modules {
    char pad[0x64];
    soNullable* work;
    char pad68[0x40];
    soNullable* status;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
    void fn_27_17C48C(void*, Access*);
    void fn_27_17B634(void*, Access*);
    void fn_27_17C650(void*, Access*);
    void fn_27_17CD5C(void*, Access*);
}

extern "C" void fn_27_17AFD4(void* self, Access* acc) {
    int kind = acc->modules->status->slot16(0);
    acc->modules->work->slot5(kind, 0x20000000);
    acc->modules->work->slot5(0xa4, 0x20000001);
    acc->modules->work->slot5(0xa5, 0x20000002);
    acc->modules->work->slot5(0xa7, 0x20000003);
    acc->modules->work->slot5(0xa6, 0x20000004);
    acc->modules->work->slot5(0xa8, 0x20000005);
    acc->modules->work->slot5(0xa9, 0x20000006);
    acc->modules->work->slot5(0xaa, 0x20000007);
    acc->modules->work->slot5(0xad, 0x20000008);
    acc->modules->work->slot5(0xac, 0x20000009);
    acc->modules->work->slot5(0xab, 0x2000000a);
    acc->modules->work->slot5(0xae, 0x2000000b);
    switch (kind) {
    case 0x2c:
        fn_27_17C48C(self, acc);
        break;
    case 0x3d:
        fn_27_17B634(self, acc);
        break;
    case 0x18:
        fn_27_17C650(self, acc);
        break;
    case 0xd:
        fn_27_17CD5C(self, acc);
        break;
    }
}
