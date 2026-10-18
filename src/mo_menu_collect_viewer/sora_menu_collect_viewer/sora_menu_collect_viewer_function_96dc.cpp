#include <types.h>
#pragma force_active on

extern "C" int fn_6_96DC(void* object) {
    char* self = static_cast<char*>(object);
    int count = *reinterpret_cast<int*>(self + 0x788);
    count = count - 1;
    *reinterpret_cast<int*>(self + 0x788) = count;
    if (count >= 0) {
        return *reinterpret_cast<int*>(self + 0x124);
    }
    return 3;
}
