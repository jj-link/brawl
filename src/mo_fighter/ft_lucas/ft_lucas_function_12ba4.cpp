#pragma force_active on
struct WorkView {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual int getInt(int);
    virtual void setInt(int, int);
};

struct ModC {
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
    virtual void s50();
    virtual void s54();
    virtual void call58(int, int);
};

struct ModD {
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
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void call60(int, bool, bool);
};

struct Access {
    char pad0[0x50];
    ModC* c;
    char pad54[0x10];
    WorkView* work;
    char pad68[0x20];
    ModD* d;
};

struct Accesser {
    char pad[0xD8];
    Access* access;
};

extern "C" void fn_114_12BA4(void*, Accesser* accesser, int event) {
    if (event != 0x11F && event != 0x120) {
        int id = accesser->access->work->getInt(0x20000003);
        if (id >= 0) {
            accesser->access->d->call60(id, true, true);
        }
        accesser->access->work->setInt(-1, 0x20000003);
        id = accesser->access->work->getInt(0x20000002);
        if (id >= 0) {
            accesser->access->c->call58(id, 0);
        }
        accesser->access->work->setInt(-1, 0x20000002);
    }
}
