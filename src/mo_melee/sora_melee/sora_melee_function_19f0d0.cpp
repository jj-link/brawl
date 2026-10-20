#include <types.h>
#pragma force_active on

struct Foo {
    u32 a;
    u32 b;
    u32 lo : 9;
    u32 kind : 1;
    u32 hi : 22;
};

extern "C" u32 fn_27_19F0D0(Foo* p) {
    return p->kind;
}
