#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3DC4(void* p, s16 flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
