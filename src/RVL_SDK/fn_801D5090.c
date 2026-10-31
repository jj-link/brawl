#include <types.h>

#pragma force_active on

#define PASTE(a, b) a##b
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void PPCMtl2cr(RG u32 val) {
    BLOCK { mtl2cr val }
}
