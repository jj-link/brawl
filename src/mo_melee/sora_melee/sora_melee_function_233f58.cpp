#include <types.h>
#pragma force_active on

extern "C" {
    void* __dynamic_cast(void* obj, long offset, const void* src, const void* tgt, short flags);
    extern const unsigned char lbl_27_data_4BCF8;
    extern const unsigned char __RTTI__10gfCallBack;
}

extern "C" void fn_27_233F58(void* self, void* cb)
{
    void* head = *(void**)((char*)self + 0x24);
    if (head) {
        void* node = head;
        while (*(void**)node)
            node = *(void**)node;
        *(void**)node = cb;
    } else {
        *(void**)((char*)self + 0x24) = __dynamic_cast(cb, 4, &lbl_27_data_4BCF8, &__RTTI__10gfCallBack, 0);
    }
}
