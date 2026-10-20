#include <types.h>
#pragma force_active on

struct FnObj27 {
    u8 pad[0x18];
    void *field18;
};

extern "C" void *fn_27_1DC748(FnObj27 *p)
{
    void *v = p->field18;
    if (v != 0) {
        return v;
    }
    return 0;
}
