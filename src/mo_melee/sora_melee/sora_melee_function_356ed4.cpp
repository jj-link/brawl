#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
}

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 getInt(u32, void*);
};

struct Effect {
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
    virtual void apply(int, int, int);
};

struct Target {
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
    virtual void v13();
    virtual int test(int);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void clear(int);
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

extern "C" void fn_27_356ED4(void*, Accesser* accesser, int status) {
    if (status != 0x117 && status != 0x14C) {
        u32 result = accesser->modules->work->getInt(0x20000006, (void*)accesser->modules);
        accesser->modules->effect->apply(result, 0, -1);
    }
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, (void*)accesser, 1)) {
    case 0x117:
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
        return;
    default:
        int i = 3;
        Target* target = accesser->modules->target;
        for (; i < 7; ++i) {
            if (target->test(i)) {
                accesser->modules->target->clear(i);
            }
        }
    }
}