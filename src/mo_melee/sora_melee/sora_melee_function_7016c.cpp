#include <types.h>
#pragma force_active on

extern "C" {
void __dt__6gfTaskFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_27_7016C(void* self, int flag) {
    if (self) {
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
