#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#pragma force_active on
extern "C" {
extern char lbl_41_data_E965[];
extern char lbl_41_data_E984[];
void fn_41_46664(wnemSimple* wn) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entered = wn->unk2214;
    wn->unk2214 = false;
    if (entered) {
        wnemCommonProc::Report(lbl_41_data_E965);
        wn->setProcFnc_HitShell(0x18);
        if (wn->setProcFnc_LifeZero(0x18) == true) {
            wnemCommonProc::Report(lbl_41_data_E984);
        }
        wn->changeMotion(1, true);
        wn->executeAnimCmd(9U);
    }
    if (data[13]) {
        wn->executeAnimCmd(data[13], 2, 1);
    }
}
}