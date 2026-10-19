#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

struct fnDisposable {
    ~fnDisposable() { }
};

extern "C" fnDisposable* fn_27_2AE068(fnDisposable* p, s32 n) {
    if (p != nullptr) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
