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
extern char lbl_41_data_E5B3[];
extern float lbl_41_rodata_F8C;
extern "C" bool fn_41_31960(wnemSimple*, unsigned long);
extern "C" int fn_41_33AD0(float*, Accesser*);
extern "C" void fn_41_445F4(wnemSimple* wn, Accesser* acc) {
    s32* data = wn->unk2234;
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_E5B3);
        wn->SetDeadMode();
        acc->modules->obj->fn_41_C59C();
        wn->executeAnimCmd(0U);
        if (fn_41_31960(wn, 2)) wn->executeAnimCmd(2U);
        if (fn_41_31960(wn, 6)) wn->executeAnimCmd(6U);
        if (fn_41_31960(wn, 3)) wn->executeAnimCmd(3U);
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_F8C;
        wn->setVisibilityWhole(0);
    }
    bool hasFrame = false;
    if (data && (data, fn_41_33AD0((float*)(data + 4), acc))) {
        hasFrame = true;
    }
    if (hasFrame) {
        unsigned int frame = fn_41_33AD0((float*)(data + 4), acc);
        if (wn->getFrameCounter(1) >= frame) {
            acc->modules->obj->fn_41_C59C();
            wn->RequestDeactive();
        }
    } else {
        acc->modules->obj->fn_41_C59C();
        wn->RequestDeactive();
    }
}