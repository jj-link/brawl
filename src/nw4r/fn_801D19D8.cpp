#include <types.h>
#pragma force_active on

extern "C" void fn_801B92D0(s32 a, s32 b);

extern "C" void fn_801D19D8(s32* self, s32 arg1) {
    s32* outer = self;
    s32* inner;
    s32 outer_c = 0;
    s32 inner_c;
    while (outer_c < self[0x27]) {
        inner = outer;
        inner_c = 0;
        while (inner_c < self[0x28]) {
            s32 val = inner[3];
            if (val != 0) {
                fn_801B92D0(val, arg1);
            }
            inner++;
            inner_c++;
        }
        outer += 4;
        outer_c++;
    }
}
