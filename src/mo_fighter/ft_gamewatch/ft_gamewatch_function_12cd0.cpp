#include <stddef.h>
#pragma force_active on

extern "C" {

extern void __dl__FPv(void*);

void* fn_107_12CD0(void* slot, short destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}

}
