#include <types.h>
#pragma force_active on

struct FtParamTable {
    s32 words[0x54];
};

extern "C" s32 fn_113_22ED4(const FtParamTable* object, void*, s32 selector, s32) {
    s32 idx = selector - object->words[6];
    return object->words[idx + 0x54];
}
