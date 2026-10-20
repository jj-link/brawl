#include <types.h>
#pragma force_active on

extern u8 __vt__25soControllerModuleLinkRef[];

extern "C" {
void fn_27_58264(void*, short, void*, void*);

void* fn_27_281634(void* self, s32 a, short b, void* c, void* d) {
    fn_27_58264(self, b, c, d);
    u8* vt = __vt__25soControllerModuleLinkRef;
    ((s32*)self)[5] = a;
    ((u8**)self)[0] = vt;
    ((u8**)self)[1] = vt + 0x110;
    ((s32*)self)[6] = 0;
    return self;
}
}
