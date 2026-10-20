#include <types.h>
#pragma force_active on

extern "C" int fn_27_CB0B0(void* p) {
    int v = *(int*)((char*)p + 8);
    return v >> 27;
}
