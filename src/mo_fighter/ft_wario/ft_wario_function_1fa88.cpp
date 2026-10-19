#include <stddef.h>
#pragma force_active on

extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1FA88(void* self, void* p2) {
    if (self != NULL) {
        __dt__21ftExtendParamAccesserFv(self, 0);
        if ((short)p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
