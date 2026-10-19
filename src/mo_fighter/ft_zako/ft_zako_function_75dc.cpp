#include <st/module.h>
#pragma force_active on

struct S {
    char pad[0x14];
    const float* floats;
};

extern "C" float fn_126_75DC(const S* s, int index) {
    return s->floats[index];
}
