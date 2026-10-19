#include <st/module.h>
#pragma force_active on

extern "C" void fn_107_3390(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_3334(void* self, short flag) {
    if (self != 0) {
        short neg = -1;
        fn_107_3390(self, neg);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
