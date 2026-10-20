#include <stddef.h>
#pragma force_active on

typedef struct {
    int _0;
    int _4;
    int _8;
} Foo;

extern "C" int fn_27_1995F4(const Foo* p) {
    int v = p->_8;
    return v >> 29;
}
