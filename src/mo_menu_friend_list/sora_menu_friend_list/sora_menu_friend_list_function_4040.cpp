#include <types.h>
#pragma force_active on

extern "C" {
void fn_800BF830(void*);
void exit__6gfTaskFv(void*);
}

extern "C" s32 fn_14_4040(u8* self) {
    u8* obj = *(u8**)(self + 0x24EC);
    if (*(s32*)(obj + 0x104) == 3) {
        fn_800BF830(obj);
        exit__6gfTaskFv(*(void**)(self + 0x24EC));
        *(void**)(self + 0x24EC) = nullptr;
        return 2;
    }
    return *(s32*)(self + 0x24C4);
}
