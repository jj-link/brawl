#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_120_9940(void* self, short flags);
}

void* fn_120_9940(void* self, short flags) {
    if (self != NULL && flags > 0) {
        operator delete(self);
    }
    return self;
}
