#include <types.h>
#pragma force_active on

struct Dummy35C {
    u32 unk[10];
};

extern "C" Dummy35C lbl_27_bss_35C;

extern "C" Dummy35C* fn_27_2DA1F4() {
    return &lbl_27_bss_35C;
}
