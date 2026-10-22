#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);

extern "C" u16 fn_8016F198(void* list, void** out, s32 max) {
    u16 count = 0;
    void* node = 0;
    goto call;
loop:
    out[count] = node;
    count++;
    if ((s32)count >= max) {
        goto done;
    }
call:
    node = fn_8015C1B0(list, node);
    if (node != 0) {
        goto loop;
    }
done:
    return count;
}
