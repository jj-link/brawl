#include <types.h>
#pragma force_active on

int fn_8022F8E8(char* p)
{
    int v = *(int*)(p - 8);
    switch (v) {
    default:
        return v + 8;
    case 0:
        return 0;
    }
}
