#include <types.h>
#pragma force_active on

extern "C" void fn_8015BF9C(void*, int);

extern "C" void* fn_801648C0(void* arg0) {
    fn_8015BF9C(arg0, 0);
    fn_8015BF9C(reinterpret_cast<char*>(arg0) + 0xC, 0);
    *(s16*)((u8*)arg0 + 0x18) = 0;
    return arg0;
}
