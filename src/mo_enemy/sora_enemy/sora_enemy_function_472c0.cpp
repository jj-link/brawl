#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#pragma force_active on

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
extern char lbl_41_data_EC9A[];
extern float lbl_41_rodata_1010;

extern "C" void fn_41_472C0(wnemSimple* wn, Accesser* acc) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_EC9A);
        acc->modules->obj->fn_41_C59C();
        wn->unk21B6 = true;
        wn->unk21B8 = false;
        wn->unk21BB = false;
        wn->unk21B9 = false;
        if (data[1]) {
            wn->executeAnimCmd(data[1], 4, 1);
        }
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_1010;
        wn->setVisibilityWhole(0);
    }
    if (wn->getFrameCounter(1) >= (u32)data[0]) {
        acc->modules->obj->fn_41_C59C();
        wn->RequestDeactive();
    }
}