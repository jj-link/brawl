#pragma force_active on

struct Iface1 {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual int func4(int, void*);
    virtual void func5(int, int);
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void func18(int);
    virtual void func19(int);
};

struct Iface2 {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void func3(int, int, int);
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void func16(int, int);
};

struct Iface3 {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void func39(int);
};

struct Obj {
    char data[0x3c];
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual int func39();
    virtual int func40();
};

struct Container {
    char pad0[0x64];
    Iface1* iface1;
    char pad1[0x1c];
    Iface2* iface2;
    Iface3* iface3;
};

struct Arg {
    char pad0[8];
    Obj* obj;
    char pad1[0xcc];
    Container* container;
};

extern "C" int fn_27_33CB58(void*, Arg* arg) {
    int result1 = arg->obj->func39();
    int result2 = arg->obj->func40();
    if (result1 != 0) {
        return 0;
    }
    if (result2 != 0xe && result2 != 5) {
        return 0;
    }

    Iface1* iface1 = arg->container->iface1;
    Iface2* iface2 = arg->container->iface2;
    int count = iface1->func4(0x10000040, arg->container);
    iface1->func18(0x22000012);

    if (result2 == 0xe) {
        iface2->func16(1, 0);
        for (int i = 0; i < count; i++) {
            iface2->func3(0, 0, 0);
        }
    } else if (result2 == 5) {
        iface2->func16(0xe, 0);
        for (int i = 0; i < count; i++) {
            iface2->func3(0xd, 0, 0);
        }
    }

    iface1->func5(0, 0x10000040);
    iface1->func19(0x1200003d);

    Iface3* iface3 = arg->container->iface3;
    iface3->func39(0x1a);

    return 0;
}
