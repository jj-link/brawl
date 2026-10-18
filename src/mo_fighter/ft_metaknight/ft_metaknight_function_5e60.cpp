#include <types.h>
#pragma force_active on

extern char lbl_111_data_1E00[];

struct MetaKnightHeaderData {
    void* vtable;
    u8 flag;
};

extern "C" void fn_111_5E60(MetaKnightHeaderData* self, u8 flag) {
    self->vtable = lbl_111_data_1E00;
    self->flag = flag;
}
