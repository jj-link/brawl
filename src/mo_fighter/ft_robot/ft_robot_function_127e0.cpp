#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_120_127E0(void* self, short size) {
    if (self != NULL && size > 0) {
        operator delete(self);
    }
    return self;
}
