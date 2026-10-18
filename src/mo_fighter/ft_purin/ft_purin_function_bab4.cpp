#pragma force_active on
struct Work {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual int isFlag(int);
    virtual void pad50();
    virtual void offFlag(int);
};

struct Motion {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void set(int, int);
    virtual int get(int, bool);
};

struct Modules {
    char pad[0x1c];
    Motion* motion;
    char pad20[0x44];
    Work* work;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_124_BAB4(void*, Fighter* fighter) {
    if (fighter->modules->work->isFlag(0x22000012)) {
        fighter->modules->work->offFlag(0x22000012);
    }

    if (fighter->modules->work->isFlag(0x22000011)) {
        if (fighter->modules->motion->get(0, false)) {
            fighter->modules->motion->set(0, 1);
            fighter->modules->work->offFlag(0x22000011);
        }
    }
}
