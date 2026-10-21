#pragma force_active on
extern float lbl_92_rodata_38;

struct ParamModule {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int get(int, int);
};

struct WorkModule {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void setInt(int, int);
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void setFloat(float, int);
};

struct Modules {
    char pad00[0x50];
    ParamModule* param;
    char pad54[0x10];
    WorkModule* work;
};

struct Accesser {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_92_DB28(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    WorkModule* work = modules->work;
    work->setInt(modules->param->get(0x1B4B, 1), 0x10000042);
    work->setInt(-1, 0x2000000A);
    work->setFloat(lbl_92_rodata_38, 0x21000006);
    work->setFloat(lbl_92_rodata_38, 0x21000007);
    work->setFloat(lbl_92_rodata_38, 0x21000008);
    work->setInt(0, 0x10000043);
}
