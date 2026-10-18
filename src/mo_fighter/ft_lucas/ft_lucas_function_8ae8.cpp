#include <types.h>
#pragma force_active on

extern "C" extern char lbl_114_data_3D48[];

struct Ft_lucas_vt_holder {
    void* vtable;
    u8 flag;
};

extern "C" void fn_114_8AE8(Ft_lucas_vt_holder* self, u8 value) {
    self->vtable = lbl_114_data_3D48;
    self->flag = value;
}
