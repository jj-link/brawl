#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <types.h>
#pragma force_active on

extern const char lbl_41_data_EB4F[];

extern "C" void fn_41_46DCC(wnemSimple* wn) {
    bool r4 = wn->unk2214;
    wn->unk2214 = false;
    if (r4) {
        wnemCommonProc::Report(lbl_41_data_EB4F);
    }
}
