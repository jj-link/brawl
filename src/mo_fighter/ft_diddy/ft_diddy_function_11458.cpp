#include <stddef.h>
#pragma force_active on

extern "C" unsigned char lbl_115_data_7AC8[];

extern "C" void* fn_115_11458(void* object)
{
    *(void**)object = lbl_115_data_7AC8;
    return object;
}
