#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

struct emTest {
    ~emTest() { }
};

extern "C" {
emTest* fn_41_15738(emTest* p, s16 flags) {
    if (p != nullptr && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
