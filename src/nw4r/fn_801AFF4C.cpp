#include <types.h>
#pragma force_active on

struct Xyz {
    void* m_ptr;
    int m_index;
    int m_value;
};

struct Yzz {
    u8 pad[0x140];
    s32* m_array;
};

extern "C" s32 fn_801AFF4C(Xyz* self, s32 arg) {
    Yzz* ptr = (Yzz*)self->m_ptr;
    if (ptr != NULL && self->m_value != 0) {
        if (arg != 0) {
            ptr->m_array[self->m_index] |= 1;
        }
        return self->m_value;
    }
    return 0;
}
