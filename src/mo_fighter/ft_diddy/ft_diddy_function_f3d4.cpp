#pragma force_active on
struct Work {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void setInt(int, int);
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void setFloat(float, int);
};

struct Posture {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual float lr();
};

struct Modules {
    char pad0[8];
    Posture* posture;
    char padC[0x58];
    Work* work;
};

struct Fighter {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_115_F3D4(void*, Fighter* fighter) {
    fighter->modules->work->setInt(1, 0x20000000);
    Work* work = fighter->modules->work;
    float lr = fighter->modules->posture->lr();
    work->setFloat(lr, 0x2100000C);
}
