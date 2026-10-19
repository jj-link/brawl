#include <types.h>
#pragma force_active on

class Ground {
public:
    s32 getNodeIndex(u32* out, u32 nodeId, const char* name);
};

extern char lbl_81_data_1D40[];
extern "C" s32 fn_81_4D38(Ground* ground);

extern "C" {
s32 fn_81_8234(Ground* ground)
{
    s32 ret = fn_81_4D38(ground);
    ground->getNodeIndex((u32*)((char*)ground + 0x1B0), 0, lbl_81_data_1D40);
    return ret;
}
}
