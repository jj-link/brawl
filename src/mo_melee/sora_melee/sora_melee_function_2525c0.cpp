#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[0x3c];
    char* m_ptr;
};

extern "C" void fn_27_248C90(fn27Obj* self, int arg);
extern "C" extern char lbl_27_data_4FC84[];

extern "C" fn27Obj* fn_27_2525C0(fn27Obj* self) {
    fn_27_248C90(self, 0);
    self->m_ptr = lbl_27_data_4FC84;
    return self;
}
