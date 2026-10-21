#include <types.h>
#pragma force_active on

extern "C" u16 fn_8015DB18(void *arg0) {
    return *(u16 *)((char *)*(void **)((char *)arg0 + 0x10) + 0xE);
}
