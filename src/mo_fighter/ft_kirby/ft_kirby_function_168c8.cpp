#pragma force_active on
class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4();
    virtual int fn_96_23CE4(int);
};
class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, unsigned int);
};
struct Modules {
    char pad[0x54];
    Class_CD28* b;
    char pad1[0xc];
    Work* a;
};
struct Fighter {
    char pad[0xd8];
    Modules* modules;
};
extern "C" void fn_96_168C8(void*, Fighter* fighter) {
    fighter->modules->a->setInt(0, 0x1000004B);
    fighter->modules->b->fn_96_23CE4(0);
    Work* a = fighter->modules->a;
    a->setInt(fighter->modules->b->fn_96_23CE4(0), 0x20000006);
    fighter->modules->a->setInt(0, 0x20000007);
    fighter->modules->a->setInt(0, 0x20000008);
}