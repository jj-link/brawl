#include <types.h>
#pragma force_active on

struct Unknown1224 {
    char pad[0x4c8];
    float f;
};

extern "C" float fn_27_112E48(Unknown1224** p)
{
    return (*p)->f;
}
