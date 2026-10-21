#include <types.h>
#pragma force_active on

extern "C" int fn_800C39D8(void*);

extern "C" s32 fn_800F2894(char* arg0) {
    if (*(int*)(arg0 + 0x60) != 0) {
        return 0;
    }
    if (fn_800C39D8(*(void**)(arg0 + 0xAC)) != 0) {
        return *(int*)(arg0 + 0x90);
    }
    return 0;
}
