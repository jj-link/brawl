#include <types.h>
#pragma force_active on

struct Module {
    u32 filler[3];
    u32 *funcs;
};

extern "C" u32 fn_109_9374(Module *module, u32 slot);

extern "C" u32 fn_109_9374(Module *module, u32 slot)
{
    u32 func = module->funcs[slot];

    return func;
}
