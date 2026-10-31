#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>

#pragma dollar_identifiers on
#pragma force_active on

extern s32 workBase$8576;

class WorkMod {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual s32 get(u32 id);
    virtual void set(s32 value, u32 id);
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void offFlag(u32 id);
};

struct ModHolder;

class OtherMod {
public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void set(s32 value, ModHolder* modules);
};

struct ModHolder {
    char pad0[0x64];
    WorkMod* work;
    char pad1[0x20];
    OtherMod* other;
};

struct Acc {
    char pad[0xd8];
    ModHolder* modules;
};

struct IndefVal {
    s32 pad0;
    s32 pad1;
    s32 a;
    s32 pad2;
    s32 b;
};

extern "C" void fn_27_1730A0(void* unused, Acc* accesser) {
    s32 workBase = 0x20000000;
    s32 val = accesser->modules->work->get(workBase + 3);

    if (val) {
        accesser->modules->other->set(val, accesser->modules);
        accesser->modules->work->set(0, workBase + 3);
    }

    s32& result = workBase;
    s32 v = accesser->modules->work->get(0x10000029);
    switch (v) {
        case 0:
            result = soValueAccesser::getConstantInt(
                (soModuleAccesser*)accesser, 0x5a3a, 0);
            break;
        case 1:
            result = ((IndefVal*)soValueAccesser::getConstantIndefinite(
                (soModuleAccesser*)accesser, 0xa812, 0))->a;
            break;
        case 2:
            result = ((IndefVal*)soValueAccesser::getConstantIndefinite(
                (soModuleAccesser*)accesser, 0xa813, 0))->b;
            break;
    }

    accesser->modules->work->set(result, 0x1000002a);
    accesser->modules->work->offFlag(0x12000000);
}
