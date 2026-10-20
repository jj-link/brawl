#include <types.h>
#pragma force_active on

class SomeObject {
public:
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" u32 fn_27_1A3DFC(SomeObject* obj)
{
    return (obj->unk8 >> 1) & 1;
}
