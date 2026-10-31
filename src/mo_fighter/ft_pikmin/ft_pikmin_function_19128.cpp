#pragma force_active on
namespace {
struct StatusModule {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int getStatusKind(); // offset 0x48
};

struct ModuleEnumeration {
    char pad[0x70];
    StatusModule* status; // 0x70
};

struct ModuleAccesser {
    char pad[0xD8];
    ModuleEnumeration* enumeration; // 0xD8
};

struct ObjBase {
    char d[0x3C];
};

#define T10(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4(); virtual void x##5(); virtual void x##6(); virtual void x##7(); virtual void x##8(); virtual void x##9();
struct Obj : public ObjBase {
    T10(v0) T10(v1) T10(v2) T10(v3)
    T10(v4) T10(v5) T10(v6) T10(v7)
    T10(v8) T10(v9) T10(v10) T10(v11)
    T10(v12) T10(v13)
    virtual void v140();
    virtual void method(); // index 141 -> vtable offset 0x23C
    char data[0x20];       // Obj size = 0x3C + 4 + 0x20 = 0x60
};
#undef T10

struct Fighter {
    Obj obj;                // offset 0; Obj's vptr at fighter+0x3C
    ModuleAccesser* accessor; // offset 0x60
};
}

extern "C" void fn_113_19128(Fighter* fighter) {
    int statusKind = fighter->accessor->enumeration->status->getStatusKind();
    switch (statusKind) {
    case 14: case 15: case 16: case 17: case 18:
    case 20:
    case 27:
    case 37: case 38: case 39: case 40: case 41:
    case 47:
        fighter->obj.method();
        break;
    }
}
