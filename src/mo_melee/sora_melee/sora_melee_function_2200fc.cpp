#include <types.h>
#pragma force_active on

struct AiHistory {
    u8 pad[0x80];
    u32 values[16];
    u32 index;
};

extern "C" u32 fn_27_2200FC(AiHistory* history, s32 offset)
{
    if (offset < 0)
        offset = 0;
    else if (offset >= 16)
        offset = 15;

    s32 index = history->index - offset;
    if (index < 0)
        index += 16;

    u32 result;
    if (&result != 0)
        result = history->values[index];
    return result;
}
