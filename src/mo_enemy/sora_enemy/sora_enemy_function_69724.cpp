#include <types.h>
#pragma force_active on

extern "C" void fn_41_69BF0(void* self, short count);
extern "C" void fn_41_696B8(void* self, short count);

extern "C" {
void* fn_41_69724(char* self, short flag) {
    if (self != nullptr) {
        short neg = -1;
        fn_41_69BF0(self + 0x1b8, neg);
        fn_41_696B8(self + 4, neg);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
