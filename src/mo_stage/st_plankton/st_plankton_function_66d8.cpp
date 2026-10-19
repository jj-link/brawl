#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
struct Foo {
    virtual ~Foo() {}
};

Foo* fn_74_66D8(Foo* p, int n) {
    if (p != NULL) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
