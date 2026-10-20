#include <types.h>
#pragma force_active on

struct Struct60 {
    u8 pad[0x60];
    int m60;
};

extern "C" int fn_27_112C70(Struct60 **arg0)
{
    return (*arg0)->m60;
}
