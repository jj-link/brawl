#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
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
    virtual void slot16();
    virtual int slot17(int, void*);
};

struct Modules {
    char pad[0x64];
    soNullable* work;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" int fn_27_151B2C(int, Accesser* p) {
    union Flag {
        unsigned int i;
        unsigned char* p;
    } flag;

    flag.p = (unsigned char*)0x12000011;
    return p->modules->work->slot17(flag.i, p->modules);
}
