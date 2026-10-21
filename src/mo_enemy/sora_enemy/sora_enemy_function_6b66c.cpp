#include <wn/wn_em_simple.h>
#pragma force_active on

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern char lbl_41_data_1FE48[];
extern float lbl_41_rodata_11D0;

extern "C" void fn_41_6B66C(wnemSimple* wn) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }

    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        Report__14wnemCommonProcFPCce(lbl_41_data_1FE48);
        wn->unk21B6 = true;
        wn->unk21B8 = false;
        wn->unk21BB = false;
        wn->unk21B9 = false;
        wn->setVisibilityWhole(0);

        if (data[1]) {
            wn->executeAnimCmd(data[1], 4, 1);
        }
        wn->executeAnimCmd(1);

        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 =
            lbl_41_rodata_11D0;
    }

    if (wn->getFrameCounter(1) >= (u32)data[0]) {
        wn->RequestDeactive();
    }
}
