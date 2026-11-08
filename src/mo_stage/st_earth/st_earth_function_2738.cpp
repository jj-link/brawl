#include <types.h>
#pragma force_active on

struct ParamsA {
    char pad[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
};

struct OwnerA {
    char pad[0x9c];
    ParamsA* params;
};

extern "C" {
float randf__Fv();
}

extern "C" int fn_66_2738(OwnerA* self, int arg1) {
    ParamsA* p = self->params;
    if (p == 0) {
        return 0;
    }

    float a = p->f14;
    float b = p->f18;
    float c = p->f1c;
    switch (arg1) {
    case 0:
        a *= p->f20;
        break;
    case 1:
        b *= p->f20;
        break;
    case 2:
        c *= p->f20;
        break;
    }

    float r = (c + (a + b)) * randf__Fv();
    if (r < a) {
        return 0;
    }
    if (r < a + b) {
        return 1;
    }
    return 2;
}
