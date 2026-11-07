#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" u8* fn_8004E5D8(void*, int);
extern "C" int fn_80058F64(int arg0) {
    int off;
    int result = 0;
    int index = 0;
    switch (arg0) {
    case 4: case 0x46: case 0x4a: case 0x4d: index = 0; break;
    case 0xb: case 0x12: case 0x16: case 0x2a: index = 1; break;
    case 0x23: case 0x3a: case 0x58: case 0x61: index = 2; break;
    case 8: case 0x38: case 0x43: case 0x6a: index = 3; break;
    case 0x1d: case 0x1f: case 0x63: case 0x68: index = 4; break;
    }
    off = index * 4;
    u32 count = 0;
    u32 minv = -1;
    for (int i = 0; i < 0x23; i++) {
        if (((*(u32*)(fn_8004E5D8(g_GameGlobal, i) + off + 0xcc) >> 30) & 1) == 1) {
            count++;
            u32 value = *(u32*)(fn_8004E5D8(g_GameGlobal, i) + off + 0xcc) & 0x3fffffff;
            if (value < minv) minv = value;
        }
    }
    switch (arg0) {
    case 0x4d: if (count != 0) result = 1; break;
    case 0x46: if (count >= 10) result = 1; break;
    case 0x4a: if (count >= 0x23) result = 1; break;
    case 4: if (minv <= 0x384) result = 1; break;
    case 0x12: if (count != 0) result = 1; break;
    case 0x16: if (count >= 10) result = 1; break;
    case 0x2a: if (count >= 0x23) result = 1; break;
    case 0xb: if (minv <= 0x474) result = 1; break;
    case 0x23: if (count != 0) result = 1; break;
    case 0x3a: if (count >= 10) result = 1; break;
    case 0x61: if (count >= 0x23) result = 1; break;
    case 0x58: if (minv <= 0x4b0) result = 1; break;
    case 0x6a: if (count != 0) result = 1; break;
    case 0x38: if (count >= 10) result = 1; break;
    case 0x43: if (count >= 0x23) result = 1; break;
    case 8: if (minv <= 0x780) result = 1; break;
    case 0x68: if (count != 0) result = 1; break;
    case 0x1d: if (count >= 10) result = 1; break;
    case 0x63: if (count >= 0x23) result = 1; break;
    case 0x1f: if (minv <= 0x708) result = 1; break;
    }
    return result;
}