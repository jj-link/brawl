#include <cstddef>
#pragma force_active on

extern "C" {
typedef void ftWarioObj;
void* fn_110_4FB4(void*, short);
void __dl__FPv(void*);

void* fn_110_B634(ftWarioObj* this_, short flag) {
    if (this_ != 0) {
        fn_110_4FB4(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
}
