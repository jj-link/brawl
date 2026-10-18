#include <cstddef>
#pragma force_active on

extern "C" void* fn_41_FB10(void* p, short n) {
    if (p != NULL && n > 0) {
        ::operator delete(p);
    }
    return p;
}
