#include <types.h>
#pragma force_active on

struct PeachClassInfo {
    void* primaryVtable;
    u32 baseState;
    void* secondaryVtable;
};

extern "C" {
extern u8 lbl_103_data_66E0[0x40];

PeachClassInfo* fn_103_1087C(PeachClassInfo* info) {
    info->primaryVtable = &lbl_103_data_66E0[0];
    return info;
}
}
