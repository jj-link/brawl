#pragma force_active on
struct Work {
    virtual void dummy8();
    virtual void dummy12();
    virtual void dummy16();
    virtual void dummy20();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
    virtual void dummy32();
    virtual void dummy36();
    virtual void dummy40();
    virtual void dummy44();
    virtual void dummy48();
    virtual void dummy52();
    virtual void dummy56();
    virtual void dummy60();
    virtual void dummy64();
    virtual void dummy68();
    virtual void dummy72();
    virtual int isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

struct Effect {
    virtual void dummy8();
    virtual void dummy12();
    virtual void dummy16();
    virtual void dummy20();
    virtual void dummy24();
    virtual void dummy28();
    virtual void dummy32();
    virtual void dummy36();
    virtual void dummy40();
    virtual void dummy44();
    virtual void dummy48();
    virtual void dummy52();
    virtual void dummy56();
    virtual void dummy60();
    virtual void dummy64();
    virtual void dummy68();
    virtual void dummy72();
    virtual void dummy76();
    virtual void dummy80();
    virtual void dummy84();
    virtual void remove(int);
};

struct Status {
    virtual void dummy8();
    virtual void dummy12();
    virtual void dummy16();
    virtual void dummy20();
    virtual void dummy24();
    virtual void dummy28();
    virtual void dummy32();
    virtual void dummy36();
    virtual void dummy40();
    virtual void dummy44();
    virtual void dummy48();
    virtual void dummy52();
    virtual void dummy56();
    virtual void dummy60();
    virtual void dummy64();
    virtual void dummy68();
    virtual void dummy72();
    virtual void dummy76();
    virtual void dummy80();
    virtual void dummy84();
    virtual void dummy88();
    virtual void dummy92();
    virtual void dummy96();
    virtual void dummy100();
    virtual void dummy104();
    virtual void dummy108();
    virtual void dummy112();
    virtual void dummy116();
    virtual void dummy120();
    virtual void dummy124();
    virtual void change(int, int, int);
};

struct Ground {
    virtual void dummy8();
    virtual void dummy12();
    virtual void dummy16();
    virtual void dummy20();
    virtual void dummy24();
    virtual void dummy28();
    virtual void dummy32();
    virtual void dummy36();
    virtual void dummy40();
    virtual void dummy44();
    virtual void dummy48();
    virtual void set(int);
};

struct Modules {
    char pad0[0x20];
    Status* status;
    char pad1[0x3c];
    Ground* ground;
    Work* work;
    char pad2[0x20];
    Effect* effect;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

struct ftManager;
struct ftOwner;

extern ftManager* g_ftManager;

extern "C" ftOwner* getOwner__9ftManagerFi(ftManager*, int);
extern "C" unsigned int fn_27_111F4C(ftOwner*);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
extern "C" void fn_27_112E54(ftOwner*, int);

extern "C" void fn_27_174198(void*, soModuleAccesser* a) {
    int id = a->modules->work->getInt(0x10000000);
    ftOwner* owner = getOwner__9ftManagerFi(g_ftManager, id);

    int handle = a->modules->work->getInt(0x20000003);
    if (handle) {
        a->modules->effect->remove(handle);
        a->modules->work->setInt(0, 0x20000003);
    }

    a->modules->work->offFlag(0x12000001);

    if (!a->modules->work->isFlag(0x12000023) &&
        fn_27_111F4C(owner) == 1) {
        int status =
            getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0x5a3e, 0);
        a->modules->status->change(status, 0, 0);
    }

    a->modules->ground->set(1);
    fn_27_112E54(owner, 0);
}
