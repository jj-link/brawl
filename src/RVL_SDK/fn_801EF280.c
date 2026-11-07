#include <types.h>
#include <revolution/GX/GXInit.h>
#pragma force_active on

void fn_801EF280(int name, int type) {
    switch (name) {
    case 0: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 0, 31, 31); break;
    case 1: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 1, 30, 30); break;
    case 2: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 2, 29, 29); break;
    case 3: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 3, 28, 28); break;
    case 4: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 4, 27, 27); break;
    case 5: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 5, 26, 26); break;
    case 6: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 6, 25, 25); break;
    case 7: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 7, 24, 24); break;
    case 8: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 8, 23, 23); break;
    case 9: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 9, 21, 22); break;
    case 10:
        if (type != 0) {
            __GXData->normal = 1;
            __GXData->binormal = 0;
            __GXData->normalType = type;
        } else {
            __GXData->normal = 0;
        }
        break;
    case 25:
        if (type != 0) {
            __GXData->binormal = 1;
            __GXData->normal = 0;
            __GXData->normalType = type;
        } else {
            __GXData->binormal = 0;
        }
        break;
    case 11: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 13, 17, 18); break;
    case 12: __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, type, 15, 15, 16); break;
    case 13: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 0, 30, 31); break;
    case 14: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 2, 28, 29); break;
    case 15: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 4, 26, 27); break;
    case 16: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 6, 24, 25); break;
    case 17: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 8, 22, 23); break;
    case 18: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 10, 20, 21); break;
    case 19: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 12, 18, 19); break;
    case 20: __GXData->vcdHiReg = __rlwimi(__GXData->vcdHiReg, type, 14, 16, 17); break;
    }
    if (__GXData->normal || __GXData->binormal) {
        __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, __GXData->normalType, 11, 19, 20);
    } else {
        __GXData->vcdLoReg &= ~0x1800;
    }
    __GXData->gxDirtyFlags |= 8;
}
