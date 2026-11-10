#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

struct Obj {
    char pad00[0x0C];
    int a0C;
    char pad10[0x10];
    unsigned int a20;
    char pad24[0x90];
    int aB4;
    int aB8;
    void* aBC;
    char padC0[0xDE - 0xC0];
    unsigned short aDE;
    unsigned short aE0;
    int aE4;
    unsigned short aE8;
    int aEC;
};

struct Inner {
    char pad00[0x50];
    int a50;
};

extern "C" {
void* fn_8015C1B0(void*, void*);
void fn_8016DE48(void*, void*);
void fn_801EC41C(const MTX34*, MTX34*);
void fn_80166B8C(void*, MTX34*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
void fn_80165EBC(void*, void*, MTX34*);

void fn_80166648(Obj* self) {
    if ((self->a20 & 0x200) == 0 && self->aB4 == 0) {
        self->aB4 = 1;
        if (self->aE8 != 0) {
            Inner* inner = (Inner*)self->aBC;
            inner->a50 |= 0x10000;
        }
        if (self->a0C == 1) {
            MTX34 sp38;
            MTX34 sp8;
            void* r31 = fn_8015C1B0((char*)self + 0xC0, 0);
            fn_8016DE48(r31, &sp8);
            fn_801EC41C(&sp8, &sp8);
            fn_80166B8C(self, &sp38);
            fn_801EC1B8(&sp8, &sp38, &sp38);
            if (self->aDE != 0) {
                self->aDE = (unsigned short)((int)self->aDE - 1);
                return;
            }
            fn_80165EBC(self, r31, &sp38);
            self->aE4 = self->aE4 + 1;
            return;
        }
        if (self->aDE != 0) {
            self->aDE = (unsigned short)((int)self->aDE - 1);
            return;
        }
        self->aE4 = self->aE4 + 1;
    }
}
}
