#include <types.h>
#pragma force_active on

struct FtKirbyObj {
    u8 pad[0x18];
    float x;
    float y;
};

extern "C" void fn_96_138F8(FtKirbyObj* obj, const float* src)
{
    obj->x = src[0];
    obj->y = src[1];
}
