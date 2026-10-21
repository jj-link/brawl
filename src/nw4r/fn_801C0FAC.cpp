#include <string.h>
#pragma force_active on

extern "C" {

unsigned fn_801C0FAC(void* arg0, void* arg1, unsigned arg2) {
    unsigned* p = (unsigned*)arg0;
    unsigned r6 = p[7];
    unsigned diff = p[6] - r6;
    unsigned size = arg2;
    if (arg2 > diff) {
        size = diff;
    }
    memcpy(arg1, (void*)(r6 + p[5]), size);
    return size;
}

}
