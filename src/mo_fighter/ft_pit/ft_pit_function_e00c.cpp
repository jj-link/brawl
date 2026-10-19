#pragma force_active on
struct WorkModule {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void onFlag(int);
};

struct Fighter {
    char padding[8];
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void reserved22();
    virtual void reserved23();
    virtual void reserved24();
    virtual void reserved25();
    virtual void changeStatus(int);
};

struct Enumeration {
    char padding0[4];
    Fighter* fighter;
    char padding1[0x5C];
    WorkModule* work;
};

struct Accesser {
    char padding[0xD8];
    Enumeration* enumeration;
};

extern "C" void fn_112_E00C(void*, Accesser* accesser) {
    Enumeration* enumeration = accesser->enumeration;
    Fighter* fighter = enumeration->fighter;
    enumeration->work->onFlag(0x21000004);
    fighter->changeStatus(0x48);
}
