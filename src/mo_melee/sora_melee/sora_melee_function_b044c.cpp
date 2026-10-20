#include <types.h>
#pragma force_active on

struct fn_27_B044C_Entry {
    u8 pad[12];
};

extern "C" void* fn_27_B044C(void* base, int index)
{
    return (u8*)base + index * sizeof(struct fn_27_B044C_Entry) + 12;
}
