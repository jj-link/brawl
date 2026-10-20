#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_1D0D74(void* ptr) {
    struct Field {
        u32 a : 18;
        u32 b : 1;
    };
    Field* p = (Field*)(static_cast<u32*>(ptr) + 2);
    return p->b;
}
