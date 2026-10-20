#include <types.h>
#pragma force_active on

extern "C" int fn_27_2914BC(const void* p) {
    union U {
        u32 raw;
        struct {
            unsigned : 6;
            signed kind : 6;
            unsigned : 20;
        };
    } u;
    u.raw = *(const u32*)((const char*)p + 8);
    return u.kind;
}
