#include <types.h>
#pragma force_active on

struct FtPikminState {
    void* vtbl;
    u8 flag;
    void* field8;
    s32 field12;
};

extern "C" {
extern char lbl_113_data_AD50[];

void fn_113_241EC(FtPikminState* state) {
    state->flag = 0;
    state->vtbl = lbl_113_data_AD50;
    state->field8 = 0;
    state->field12 = -1;
}
}
