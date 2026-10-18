#include <types.h>
#pragma force_active on

extern "C" u8 lbl_41_data_1638[];
extern "C" void removeEnemyAll__9emManagerFv(void*);
extern "C" void removeArchiveAll__9emManagerFv(void*);
extern "C" void __dla__FPv(void*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_6FDE0(u32);

extern "C" void* fn_41_C934(void* self, s16 flag) {
    if (self != NULL) {
        *(void**)((u8*)self + 0x1C) = (void*)lbl_41_data_1638;
        removeEnemyAll__9emManagerFv(self);
        removeArchiveAll__9emManagerFv(self);
        __dla__FPv(*(void**)((u8*)self + 0x04));
        __dla__FPv(*(void**)((u8*)self + 0x10));
        fn_27_6FDE0(1);
        *(u32*)((u8*)self + 0x00) = 0;
        *(u32*)((u8*)self + 0x04) = 0;
        *(u32*)((u8*)self + 0x08) = 0;
        *(u32*)((u8*)self + 0x0C) = 0;
        *(u32*)((u8*)self + 0x10) = 0;
        *(u32*)((u8*)self + 0x14) = 0;
        *(u8*)((u8*)self + 0x18) = 0;
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
