#include <types.h>
#pragma force_active on

extern "C" char* fn_8017607C(char* self) {
    char* r4 = *(char**)(self + 0x3c);
    while (r4 != 0 && *(int*)(r4 + 0x0c) != 1) {
        unsigned short r5 = *(unsigned short*)(self + 0x42);
        r4 = *(char**)(r4 + r5);
        while (r4 != 0 && *(int*)(r4 + 0x0c) != 1) {
            r4 = *(char**)(r4 + r5);
        }
    }
    return r4;
}
