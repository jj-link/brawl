#include <types.h>
#pragma force_active on

extern "C" {
__declspec(section ".data") extern u32 lbl_27_data_13250;
}

extern "C" u32* fn_27_7FEEC(void) {
    return &lbl_27_data_13250;
}
