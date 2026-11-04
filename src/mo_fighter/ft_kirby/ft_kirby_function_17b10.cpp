#pragma force_active on

class ModuleA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, unsigned int);
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
    virtual void activate(unsigned int);
    virtual int get(int);
};

class ModuleB {
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
    virtual int get(int);
};

struct Modules {
    char pad0[0x54];
    ModuleB* b;
    char pad1[0xC];
    ModuleA* a;
};

struct Fighter {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_96_17B10(void* unused, Fighter* fighter) {
    fighter->modules->a->activate(0x22000018);
    fighter->modules->a->setInt(1, 0x1000004B);
    fighter->modules->b->get(0);
    ModuleA* a = fighter->modules->a;
    a->setInt(fighter->modules->b->get(0), 0x20000006);
    fighter->modules->a->setInt(0, 0x20000007);
    fighter->modules->a->setInt(0, 0x20000008);
}