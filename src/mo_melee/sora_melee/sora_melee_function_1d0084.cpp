#include <types.h>
#pragma force_active on

struct Foo {
    int a;
    int b;
    unsigned x : 9;
    unsigned kind : 1;
    unsigned y : 22;
};

extern "C" {
s32 fn_27_1D0084(Foo* p) {
    return p->kind;
}
}
