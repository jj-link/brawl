#include <types.h>
#pragma force_active on

struct Fn801AFFDC_Outer {
    void* m_ptr;
    int m_index;
    char m_pad[0xC];
    int m_value;
};

struct Fn801AFFDC_Inner {
    char m_pad[0x140];
    void* m_array;
};

extern "C" s32 fn_801AFFDC(Fn801AFFDC_Outer* self, s32 arg1) {
    if (self->m_ptr && self->m_value) {
        if (arg1) {
            int* arr = (int*)((Fn801AFFDC_Inner*)self->m_ptr)->m_array;
            arr[self->m_index] |= 8;
        }
        return self->m_value;
    }
    return 0;
}
