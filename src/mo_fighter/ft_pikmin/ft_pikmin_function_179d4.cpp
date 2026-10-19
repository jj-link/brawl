#pragma force_active on
struct Obj;

struct Msg {
    int type;
    bool flag;
};

class CompA {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int, bool);
};

class CompB {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned int f4(int, void*);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
    virtual int f9(int);
    virtual void f10();
    virtual Obj* f11(int);
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15(int, Msg*);
};

class CompC {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Obj* f4(int);
};

class CompD {
public:
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
    virtual int f16();
};

struct Obj {
    char pad[0x28];
    void* m28;
};

struct Inner {
    char pad0[0x3c];
    CompA* c3c;
    char pad1[0x54 - 0x40];
    CompB* c54;
    char pad2[0x64 - 0x58];
    CompC* c64;
    char pad3[0x70 - 0x68];
    CompD* c70;
};

struct Mid {
    char pad[0xd8];
    Inner* inner;
};

struct Pad3c {
    char pad[0x3c];
};

class OuterV : public Pad3c {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual unsigned int v41();
    char pad2[0x20];
    Mid* mid;
};

extern "C" void fn_113_1B02C(OuterV* a);

extern "C" void fn_113_179D4(OuterV* a) {
    a->mid->inner->c3c->f9(0, false);
    if (a->v41() == 1) {
        fn_113_1B02C(a);
    }
    Obj* p30 = a->mid->inner->c54->f11(3);
    unsigned int r29 = 1;
    Obj* p28 = a->mid->inner->c64->f4(0x10000000);
    if (p30 == 0) {
        r29 = a->mid->inner->c54->f4(3, p28);
    } else if (p28 != p30->m28) {
        a->mid->inner->c54->f8(3);
        if (a->mid->inner->c54->f9(3) == 0) {
            r29 = a->mid->inner->c54->f4(3, p28);
        }
    }
    if (r29 == 1) {
        if (a->mid->inner->c70->f16() == 0x21) {
            Msg m1;
            m1.type = 0x456;
            m1.flag = false;
            a->mid->inner->c54->f15(3, &m1);
        }
        {
            Msg m2;
            m2.type = 2;
            m2.flag = false;
            a->mid->inner->c54->f15(3, &m2);
        }
    }
}
