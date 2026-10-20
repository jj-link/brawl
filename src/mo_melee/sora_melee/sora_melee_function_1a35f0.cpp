#include <types.h>
#pragma force_active on

struct Foo {
    unsigned _0;
    unsigned _4;
    int a : 20;
    int b : 10;
};

extern "C" int fn_27_1A35F0(struct Foo* obj) {
    return obj->b;
}
