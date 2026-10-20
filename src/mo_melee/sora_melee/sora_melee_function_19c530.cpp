#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_19C530(void* arg) {
    struct X {
        u32 pad0;
        u32 pad1;
        unsigned : 12;
        unsigned val : 1;
        unsigned : 19;
    };
    return ((struct X*)arg)->val;
}
