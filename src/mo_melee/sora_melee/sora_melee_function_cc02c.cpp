#include <types.h>
#pragma force_active on

extern "C" {

struct Foo {
    int x0;
    int x4;
    int c;
};

u32 fn_27_CC02C(Foo* p) {
    return (p->c >> 25) & 1;
}

}
