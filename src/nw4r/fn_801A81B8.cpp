#include <types.h>
#pragma force_active on

extern "C" {
void fn_801F55B0(void* a, void* b);

void fn_801A81B8(void** self)
{
    char* obj = (char*)*self;
    if (obj == 0)
        return;
    fn_801F55B0(*(void**)(obj + 0x104), *(void**)(obj + 0x108));
}
}
