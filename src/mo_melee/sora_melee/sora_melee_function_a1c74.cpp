#include <types.h>
#pragma force_active on

struct fn_27_A1C74_object {
    u32 unk[2];
    u32 unk8;
};

extern "C" void fn_27_A1C74(fn_27_A1C74_object *object, u32 value)
{
    u32 *field = &object->unk8;
    *field = __rlwimi(*field, value, 17, 10, 14);
}
