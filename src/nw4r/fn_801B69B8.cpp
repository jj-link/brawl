#include <types.h>
#pragma force_active on

extern "C" void* fn_801B69B8(void** arg0, u32 arg1) {
    void* obj = *arg0;
    int flag = 0;
    if (obj && *(int*)((char*)arg0 + 4))
        flag = 1;
    if (flag && arg1 < 8) {
        int offset = *(int*)((char*)arg0 + 4);
        s8 val = *(s8*)(offset + arg1);
        if (val >= 0)
            return (void*)(*(int*)((char*)obj + 4) + val * 0x44);
    }
    return NULL;
}
