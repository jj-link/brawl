#include <types.h>
#pragma force_active on

extern "C" void fn_800B9984(void*);
extern "C" int fn_800FAD8C(void*);
extern "C" void fn_800FB098(void*);

extern "C" void fn_800FB554(unsigned char* self)
{
    fn_800B9984(self + 0x100);
    *(int*)(self + 0x1a8) = fn_800FAD8C(self + 0x100);
    fn_800FB098(self);
}
