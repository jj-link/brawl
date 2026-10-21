#pragma force_active on

struct Work {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void setInt(int, int);
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void onFlag(int);
    virtual void offFlag(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Fighter {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_109_E00C(Fighter*);

extern "C" void fn_109_DA60(void*, Fighter* self) {
    Work* work = self->modules->work;
    work->onFlag(0x22000010);
    work->offFlag(0x22000011);
    work->setInt(-1, 0x20000000);
    work->offFlag(0x22000012);
    work->offFlag(0x22000013);
    work->offFlag(0x22000014);
    work->offFlag(0x22000015);
    work->onFlag(0x12000001);
    fn_109_E00C(self);
}
