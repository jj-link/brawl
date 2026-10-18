#pragma force_active on
struct ModA {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void call48(int, int);
};

struct ModB {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual int get18(int);
    virtual void set1C(int, int);
};

struct ModC {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void call58(int, int);
};

struct Access {
    char pad0[0x50];
    ModC* c;
    char pad54[0x10];
    ModB* b;
    char pad68[0x1C];
    ModA* a;
};

struct Fighter {
    char pad[0xD8];
    Access* access;
};

extern "C" void fn_92_F100(void*, Fighter* fighter, int event) {
    if (event != 0x134) {
        fighter->access->a->call48(0, 0);
        int id = fighter->access->b->get18(0x10000042);
        if (id >= 0) {
            fighter->access->c->call58(id, 0);
            fighter->access->b->set1C(-1, 0x10000042);
        }
    }
}
