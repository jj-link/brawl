#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_543A8(const void *object)
{
    return *reinterpret_cast<const s32 *>(static_cast<const char *>(object) + 8) >> 23;
}
