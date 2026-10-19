#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[0x3c];
    char* m_ptr;
};

extern "C" void fn_27_248C90(fn27Obj* self);
extern "C" extern char lbl_27_data_529B0[];

extern "C" fn27Obj* fn_27_2530D4(fn27Obj* self) {
    fn_27_248C90(self);
    self->m_ptr = lbl_27_data_529B0;
    return self;
}
