#include <types.h>
#pragma force_active on

struct Data58 {
    u8 data[0x58];
};

extern Data58 lbl_27_data_2D8F8;

extern "C" Data58* fn_27_151770() {
    return &lbl_27_data_2D8F8;
}
