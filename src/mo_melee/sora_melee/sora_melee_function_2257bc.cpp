#include <types.h>
#pragma force_active on

extern u32 lbl_27_bss_5670[66];
extern u8 lbl_27_bss_5778;
extern char lbl_27_data_4A408[];

struct stClassInfo {
    void* unk0;
    stClassInfo();
};

stClassInfo::stClassInfo() {
    unk0 = lbl_27_data_4A408;
    if (lbl_27_bss_5778 != 0) {
        return;
    }

    for (int i = 0; i < 66; ++i) {
        lbl_27_bss_5670[i] = 0;
    }

    lbl_27_bss_5778 = 1;
}
