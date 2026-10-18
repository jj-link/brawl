#include <types.h>
#pragma force_active on

struct MoveScript {
    u8 pad[8];
    u32 m20;
};

extern "C" int fn_27_7AB60(MoveScript* script);
extern "C" int fn_27_7AB60(MoveScript* script)
{
    return ((int)script->m20) >> 26;
}
