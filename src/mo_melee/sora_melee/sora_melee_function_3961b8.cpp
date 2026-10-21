#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
}

struct Target {
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
    virtual int test(int);
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
    virtual void clear(int);
};

struct Work {
    virtual void dummy8();
    virtual void dummy12();
    virtual void dummy16();
    virtual void dummy20();
    virtual int getInt(unsigned int);
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
    virtual void apply(int, int, int);
};

struct Modules {
    char pad0[0x64];
    Work* work;
    char pad1[0x28];
    Effect* effect;
    char pad2[0x14];
    Target* target;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_3961B8(void*, Accesser* accesser, int status) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x117:
        return;
    default:
        int i = 3;
        Target* target = accesser->modules->target;
        for (; i < 7; ++i) {
            if (target->test(i)) {
                accesser->modules->target->clear(i);
            }
        }
    case 0x127:
        accesser->modules->effect->apply(
            accesser->modules->work->getInt(0x20000008), 0, -1);
        break;
    }
}
