#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_14FCF4(void*, short);

extern "C" void* fn_110_30D4(void* object, short flags)
{
    if (object != NULL)
    {
        fn_27_14FCF4(object, -1);
        if (flags > 0)
        {
            operator delete(object);
        }
    }
    return object;
}
