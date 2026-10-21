#pragma force_active on

class MotionModule {
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
    virtual unsigned int query(int);
    virtual void change(int);
};

class WorkModule {
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
    virtual void clearFlag(unsigned int);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void enable(unsigned int);
    virtual void disable(unsigned int);
};

struct Modules {
    char pad0[8];
    MotionModule* motion;
    char pad1[0x64 - 0x0c];
    WorkModule* work;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_16EA10(void*, Owner* owner) {
    int kind;
    if (owner->modules->motion->query(0xbc) == 1U) {
        kind = 0xbc;
        owner->modules->work->enable(0x22000019);
    } else {
        kind = 0xbd;
        owner->modules->work->disable(0x22000019);
    }
    owner->modules->work->setInt(kind, 0x20000008);
    owner->modules->motion->change(kind);
    owner->modules->work->clearFlag(0x21000008);
}
