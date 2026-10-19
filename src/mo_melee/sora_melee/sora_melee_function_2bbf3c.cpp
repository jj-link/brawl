#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2BC3B0(void*, u32);
extern "C" void fn_27_2BBC24(void*, void*);

extern "C" void fn_27_2BBF3C(void* self) {
    void* v = fn_27_2BC3B0(self, 0);
    fn_27_2BBC24(self, v);
}
