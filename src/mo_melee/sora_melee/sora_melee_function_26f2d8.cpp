#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_57184[];

struct fnObj26F2D8 {
    void* vtbl;
    u8 flag;
};

void fn_27_26F2D8(fnObj26F2D8* self) {
    self->flag = 0;
    self->vtbl = lbl_27_data_57184;
}
}
