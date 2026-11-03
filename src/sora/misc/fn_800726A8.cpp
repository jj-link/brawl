#pragma force_active on
#include <types.h>

extern char lbl_804543D8[];

extern "C" {
void free__13gfHeapManagerFPv(void* p);
void __dl__FPv(void* p);

void* fn_800726A8(void* self, s32 del) {
    if (self) {
        *(char**)self = lbl_804543D8;
        free__13gfHeapManagerFPv(*(void**)((char*)self + 0x24));
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
