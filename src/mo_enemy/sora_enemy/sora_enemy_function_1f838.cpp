#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_41_data_2CF8[];

struct fn41Obj {
    void* m_table;
    u8 m_flag;
};

void fn_41_1F838(fn41Obj* self) {
    self->m_flag = 0;
    self->m_table = lbl_41_data_2CF8;
}
}
