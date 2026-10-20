#include <types.h>
#pragma force_active on

struct S {
    char pad[0x80c];
    float f;
};

extern "C" float fn_27_112BA4(struct S **a) {
    return (*a)->f;
}
