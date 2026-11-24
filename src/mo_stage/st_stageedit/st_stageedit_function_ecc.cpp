#include <types.h>
#pragma force_active on

static inline u32 cellCheck(const u32* grid, u32 width, u32 height, u32 x, u32 y) {
    u32 result = 0;
    if (x >= width || y >= height) {
        result = 2;
    } else if ((1u << x) & grid[y]) {
        result = 1;
    }
    return result;
}

extern "C" u32 fn_85_ECC(void* self, u32 flags, const u32* p, const u32* grid,
                         u32 width, u32 height) {
    int special;

    if (((*(const unsigned int*)p >> 10) & 3) == 3) {
        switch ((int)((*(const unsigned int*)p >> 6) & 0xF)) {
        case 1:
        case 2:
        case 3:
        case 6:
            special = 1;
            break;
        default:
            goto zero;
        }
    } else {
    zero:
        special = 0;
    }

    if (special != 0) {
        return flags | 0x2000;
    }

    u32 word = *p;
    u32 idx = word >> 24;
    u32 x = idx % 18;
    u32 y = idx / 18;
    int w = (word >> 21) & 7;
    int h = (word >> 18) & 7;

    if (!(h & 1) && (((word & 7) == 2) || ((word & 7) == 5))) {
        y++;
    }

    x -= w / 2;
    y -= h / 2;

    if (cellCheck(grid, width, height, x - 1, y) == 1 ||
        cellCheck(grid, width, height, x + w, y) == 1) {
        flags |= 0x4000;
    }

    return flags;
}
