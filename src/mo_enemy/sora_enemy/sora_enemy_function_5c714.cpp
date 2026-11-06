#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#pragma force_active on

extern "C" {
extern char lbl_41_data_18A3D[];
extern const float lbl_41_rodata_1138;

void fn_41_5C714(wnemSimple* wn) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entered = wn->unk2214;
    wn->unk2214 = false;
    if (entered) {
        wnemCommonProc::Report(lbl_41_data_18A3D);
        wn->SetDeadMode();
        wn->setVisibilityWhole(0);
        if (data[3]) {
            wn->executeAnimCmd(data[3], 4, 1);
        }
        wn->unk2204 = lbl_41_rodata_1138;
        wn->unk2200 = lbl_41_rodata_1138;
        wn->unk21FC = lbl_41_rodata_1138;
        wn->unk21F8 = lbl_41_rodata_1138;
    }
    if (wn->getFrameCounter(1) >= (u32)data[2]) {
        wn->RequestDeactive();
    }
}
}