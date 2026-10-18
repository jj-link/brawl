#pragma force_active on

struct SecondA {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7(unsigned int);
};

struct SecondB {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10(int, int, int);
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual int b18(int);
};

struct Access {
    unsigned char pad[0x58];
    SecondA* ptrA;
    unsigned char pad2[0x84 - 0x5C];
    SecondB* ptrB;
};

struct Owner {
    unsigned char pad[0xd8];
    Access* access;
};

extern "C" void fn_96_14A80(void* owner_p, int arg) {
    Owner* owner = (Owner*)owner_p;
    Access* access = owner->access;
    SecondA* a = access->ptrA;
    SecondB* b = access->ptrB;

    unsigned int v = (unsigned int)__cntlzw(arg) >> 5;
    if (b->b18(3) != 0) {
        b->b10(3, arg, 0);
    }
    a->a7(v);
}
