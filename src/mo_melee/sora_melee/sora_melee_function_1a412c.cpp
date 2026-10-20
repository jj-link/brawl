#include <types.h>
#pragma force_active on

struct FieldHolder {
    u32 pad[2];
    struct {
        u32 a : 6;
        u32 b : 3;
        u32 c : 23;
    } bits;
};

extern "C" void fn_27_1A412C(FieldHolder* p, u32 v)
{
    p->bits.b = v;
}
