#pragma force_active on
extern "C" {
void fn_96_14A80(void*, int);
extern float lbl_96_rodata_4C;
}

struct Pad {
    unsigned char bytes[8];
};

struct First : Pad {
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void action(int);
};

struct Second {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void action(float, int);
};

struct Access {
    unsigned char pad[0x38];
    First* first;
    unsigned char pad2[0x64 - 0x3C];
    Second* second;
};

struct Owner {
    unsigned char pad[0xD8];
    Access* access;
};

extern "C" void fn_96_14B80(void*, Owner* owner) {
    Access* access = owner->access;
    First* first = access->first;
    Second* second = access->second;

    fn_96_14A80(owner, 1);
    first->action(1);
    second->action(lbl_96_rodata_4C, 0x21000004);
}
