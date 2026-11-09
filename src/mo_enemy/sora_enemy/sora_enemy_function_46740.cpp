#include <wn/wn_em_simple.h>
#include <wn/weapon.h>
#include <em/wnem/wnem_proc_common.h>
#pragma force_active on

extern char lbl_41_data_E8D8[];
extern float lbl_41_rodata_FD8;

class Class_740 {
public:
    virtual void fn_41_BDA0();
    virtual void fn_41_BE5C();
    virtual void fn_41_BFDC();
    virtual void fn_41_BDA8();
    virtual void fn_41_C59C();
};
struct Modules { char pad[0x1c]; Class_740* obj; };
struct Accesser { char pad[0xd8]; Modules* modules; };

extern "C" void fn_41_46740(wnemSimple* wn, Accesser* acc) {
    const char* base = lbl_41_data_E8D8;
    s32* data = 0;
    if (wn->unk2234) data = wn->unk2234;
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(base + 0x11b);
        wn->SetDeadMode();
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_FD8;
        wn->setVisibilityWhole(0);
        acc->modules->obj->fn_41_C59C();
        wnemCommonProc::Report(base + 0x13b);
        wn->executeAnimCmd(1U);
        wn->executeAnimCmd(4U);
    }
    u32 limit = (u32)data[10];
    if (wn->getFrameCounter(1) >= limit) {
        wnemCommonProc::Report(base + 0x17e);
        wn->RequestDeactive();
    }
}