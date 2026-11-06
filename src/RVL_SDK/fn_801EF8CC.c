#include <types.h>
#include <revolution/GX/GXInit.h>
#pragma force_active on

void fn_801EF8CC(int attr, int* type) {
    int result;

    switch (attr) {
    case 0:
        result = __GXData->vcdLoReg & 1;
        break;
    case 1:
        result = (__GXData->vcdLoReg >> 1) & 1;
        break;
    case 2:
        result = (__GXData->vcdLoReg >> 2) & 1;
        break;
    case 3:
        result = (__GXData->vcdLoReg >> 3) & 1;
        break;
    case 4:
        result = (__GXData->vcdLoReg >> 4) & 1;
        break;
    case 5:
        result = (__GXData->vcdLoReg >> 5) & 1;
        break;
    case 6:
        result = (__GXData->vcdLoReg >> 6) & 1;
        break;
    case 7:
        result = (__GXData->vcdLoReg >> 7) & 1;
        break;
    case 8:
        result = (__GXData->vcdLoReg >> 8) & 1;
        break;
    case 9:
        result = (__GXData->vcdLoReg >> 9) & 3;
        break;
    case 10:
        if (__GXData->normal != 0) {
            result = (__GXData->vcdLoReg >> 11) & 3;
        } else {
            result = 0;
        }
        break;
    case 25:
        if (__GXData->binormal != 0) {
            result = (__GXData->vcdLoReg >> 11) & 3;
        } else {
            result = 0;
        }
        break;
    case 11:
        result = (__GXData->vcdLoReg >> 13) & 3;
        break;
    case 12:
        result = (__GXData->vcdLoReg >> 15) & 3;
        break;
    case 13:
        result = __GXData->vcdHiReg & 3;
        break;
    case 14:
        result = (__GXData->vcdHiReg >> 2) & 3;
        break;
    case 15:
        result = (__GXData->vcdHiReg >> 4) & 3;
        break;
    case 16:
        result = (__GXData->vcdHiReg >> 6) & 3;
        break;
    case 17:
        result = (__GXData->vcdHiReg >> 8) & 3;
        break;
    case 18:
        result = (__GXData->vcdHiReg >> 10) & 3;
        break;
    case 19:
        result = (__GXData->vcdHiReg >> 12) & 3;
        break;
    case 20:
        result = (__GXData->vcdHiReg >> 14) & 3;
        break;
    default:
        result = 0;
        break;
    }

    *type = result;
}
