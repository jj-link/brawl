#include <types.h>
#pragma force_active on

extern "C" {
struct Foo {
    u32 a;
    u32 b;
    u32 c:9;
    u32 d:1;
    u32 e:22;
};

u32 fn_27_2EB960(Foo* self) {
    return self->d;
}
}
