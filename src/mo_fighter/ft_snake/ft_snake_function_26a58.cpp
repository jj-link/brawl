#pragma force_active on

class Class_E104 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_176B0();
    virtual void fn_122_18F4C();
    virtual void fn_122_18F44();
    virtual void fn_122_18F3C();
    virtual void fn_122_18F34();
    virtual void fn_122_18F2C();
    virtual void fn_122_18F24();
    virtual void fn_122_18F1C();
    virtual void fn_122_18F14();
    virtual void fn_122_18F0C();
    virtual void fn_122_18F04();
    virtual void fn_122_18EFC();
    virtual void fn_122_18EF4();
    virtual void fn_122_18EA4();
    virtual void fn_122_18EEC();
    virtual void fn_122_18EDC();
    virtual void fn_122_18ECC();
    virtual void fn_122_18EBC(int);
};

class Num {
public:
    virtual void v0();
    virtual void v1();
    virtual int v2();
};

class Obj18 {
public:
    virtual void v0();
    virtual void v1();
    virtual Num* v2();
};

class Obj70 {
public:
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
    virtual int v18();
};

struct BcBase {
    char pad[8];
};

class Bc : public BcBase {
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
    virtual unsigned int v13();
};

struct Mods {
    char p0[0x18];
    Obj18* f18;
    char p1[0x64 - 0x1C];
    Class_E104* f64;
    char p2[0x70 - 0x68];
    Obj70* f70;
    char p3[0xBC - 0x74];
    Bc* fBc;
};

struct Arg {
    char pad[0x20];
    signed char f20;
    unsigned char f21;
};

extern "C" void fn_122_26A58(unsigned char* self, Arg* arg) {
    if (arg == 0) {
        return;
    }
    if ((*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f70->v18() == 0) {
        if (arg->f21 == 3) {
            if ((int)arg->f20 != (*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f18->v2()->v2()) {
                if ((*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->fBc->v13() == 1U) {
                    (*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f64->fn_122_18EBC(0x22000002);
                }
            }
        } else {
            (*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f64->fn_122_18EBC(0x22000001);
        }
    } else if ((*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f70->v18() == 1) {
        if (arg->f21 == 3) {
            if ((int)arg->f20 != (*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f18->v2()->v2()) {
                (*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f64->fn_122_18EBC(0x22000001);
            }
        } else {
            (*(Mods**)(*(unsigned char**)(self + 0x60) + 0xD8))->f64->fn_122_18EBC(0x22000000);
        }
    }
}
