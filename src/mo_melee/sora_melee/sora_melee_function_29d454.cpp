#pragma force_active on
#define VIRTUAL_TEN(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9();

struct Module {
    VIRTUAL_TEN(a)
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual int getKind();
};

struct Modules {
    char padding[0x70];
    Module* module;
};

struct FighterBase {
    char padding0[0x3c];
    VIRTUAL_TEN(a)
    VIRTUAL_TEN(b)
    VIRTUAL_TEN(c)
    VIRTUAL_TEN(d)
    VIRTUAL_TEN(e)
    VIRTUAL_TEN(f)
    VIRTUAL_TEN(g)
    VIRTUAL_TEN(h)
    VIRTUAL_TEN(i)
    VIRTUAL_TEN(j)
    VIRTUAL_TEN(k)
    VIRTUAL_TEN(l)
    VIRTUAL_TEN(m)
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void changeStatus(int, int);
};

struct Fighter : FighterBase {
    char padding1[0x164];
    Modules* modules;
};

#undef VIRTUAL_TEN

extern "C" int fn_27_29D454(void*, Fighter* fighter) {
    if (fighter->modules->module->getKind() != 2) {
        return 1;
    }
    fighter->changeStatus(9, 0);
    return 1;
}
