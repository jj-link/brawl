#include <types.h>
#pragma force_active on

struct V {
    virtual void f0();
    virtual void* f1(void*);
};

extern "C" void* fn_27_1CEE84(void* a, void* b, void* c) {
    void* result = ((V*)a)->f1(c);
    *(void**)result = *(void**)b;
    return result;
}
