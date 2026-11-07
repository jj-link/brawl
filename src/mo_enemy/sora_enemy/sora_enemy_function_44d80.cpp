#include <em/wnem/wnem_proc_common.h>
#include <wn/wn_em_simple.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern const char lbl_41_data_E64C[];
extern const char lbl_41_data_E672[];
extern const float lbl_41_rodata_FA0;

extern "C" void fn_41_44D80(wnemSimple* wn, soModuleAccesser* acc) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_E64C);
        wn->executeAnimCmd(0);
        wn->executeAnimCmd(2);
        wn->unk21B7[0] = 0;
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_FA0;
        acc->getCollisionAttackModule().clearAll();
        acc->getCollisionHitModule().setXluGlobal(0);
    }
    if (wn->getFrameCounter(1) >= (u32)data[2]) {
        wnemCommonProc::Report(lbl_41_data_E672);
        wn->executeAnimCmd(1);
        wn->RequestDeactive();
    }
}