#include <types.h>
#pragma force_active on

typedef struct {
    u16 width;
    u16 unk02;
    u16 unk04;
    u8 height;
    u8 unk07;
    char pad08[20];
    u32 count;
    u8 shift_x;
    u8 shift_y;
    u8 pad22[2];
    u16 max_idx;
    char pad26[6];
    u32 base;
    u32 base2;
} Grid;

typedef struct {
    char pad0[8];
    u32 *header;
    char pad_c[40];
    Grid *grid;
} Obj;

extern int fn_803B6CA8(Obj *, u32, u32, u32 *, u32 *);
extern int fn_803B6B18(Obj *, u32, u32, u32 *);

int fn_803B6DC8(Obj *obj, u32 idx, u32 mode, u32 pos,
                u32 *out_data, u32 *out_pos)
{
    u32 spC;
    u32 sp8 = 0;
    Grid *grid = obj->grid;
    u32 count = grid->count;
    int result;
    u32 shifted;

    if (*obj->header == 1 && count <= 1) {
        if ((int)count != 0 && (int)count != 1) {
            result = 12;
        } else if (idx >= grid->max_idx) {
            *out_data = -1;
            result = 0;
        } else {
            *out_data = grid->base + idx;
            result = 0;
        }
        return result & ((-result | result) >> 31);
    }

    shifted = idx >> grid->shift_y;
    if (mode == 2) {
        u32 y = (pos >> grid->shift_x) +
                ((pos & (grid->width - 1)) != 0);
        result = fn_803B6CA8(
            obj, shifted,
            (y >> grid->shift_y) + (((grid->height - 1) & y) != 0),
            &spC, &sp8);
        if (result != 0) {
            return result;
        }
        *out_pos = sp8 << grid->shift_y;
    } else {
        result = fn_803B6B18(obj, shifted, mode, &spC);
        if (result != 0) {
            return result;
        }
        *out_pos = 1 << grid->shift_y;
    }

    if ((u32)(spC + 0x10000) == 0xffff) {
        *out_data = -1;
        return 0;
    }

    *out_data = grid->base2 + ((spC - 2) << grid->shift_y) +
                (idx & (grid->height - 1));
    return 0;
}
