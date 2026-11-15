#pragma use_lmw_stmw on
#pragma force_active on
#include <types.h>
#include <stl/internal/mem.h>

typedef struct {
    u8 pad0[0x22];
    u8 countX;
    u8 countY;
    u32 offsetX;
    u32 offsetY;
    u8 tileSize;
    u8 pad2d[0x48 - 0x2d];
    u32 pitch;
    u8 pad4c[0x64 - 0x4c];
    u16 *pixels;
} Input;

static inline u16 getTexel(u16 *source, unsigned long row, int column) {
    return source[(column & 3) + (((column >> 2) * 2 + row) * 16)];
}

static inline void unpackPixel(u16 *source, unsigned long row, int column, u8 *red, u8 *green, u8 *blue) {
    int index = (column >> 2) * 2 - -row;
    u16 ar = source[(column & 3) + ((index + 1) * 16)];
    u16 gb = source[(column & 3) + (index * 16)];
    *red = gb;
    *green = ar >> 8;
    *blue = ar;
}

int fn_8026E6A8(u8 *output, Input *input, int x, int y) {
    u8 *luma = output + 4;
    u8 *cb = output + 0x104;
    u8 *cr = output + 0x144;
    u16 *pixels = input->pixels;
    u8 red;
    u8 green;
    u8 blue;
    int column;
    int width;
    int rowEndX;
    int height;
    int rowEndY;
    int pitch = (input->pitch >> 1) & 0x7ffffffe;
    int i;

    if (input->offsetX == (u32)x) {
        width = input->countX;
    } else {
        width = 0x10 / input->tileSize;
    }
    if (input->offsetY == (u32)y) {
        height = input->countY;
    } else {
        height = 0x10 / input->tileSize;
    }
    rowEndX = x + width;
    rowEndY = y + height;
    for (; y < rowEndY; y++) {
        for (column = x; column < rowEndX; column++) {
            unpackPixel((u16 *)((u8 *)pixels + ((y & 3) * 8)),
                        (y >> 2) * pitch, column, &red, &green, &blue);
            *luma = (u8)((red * 0x4d + green * 0x96 + blue * 0x1d + 0x80) >> 8);
            if ((column & 1) == 0 && (y & 1) == 0) {
                *cb = (u8)(((blue - *luma) * 0x90 + 0x80) >> 8);
                cb++;
                *cr = (u8)(((red - *luma) * 0xb7 + 0x80) >> 8);
                cr++;
            }
            luma++;
        }
        for (i = width; i < 0x10; i++) {
            *luma = luma[-1];
            luma++;
            if ((i & 1) == 0 && (y & 1) == 0) {
                *cb = cb[-1];
                cb++;
                *cr = cr[-1];
                cr++;
            }
        }
    }
    for (; height < 0x10; height++) {
        memcpy(luma, luma - 0x10, 0x10);
        luma += 0x10;
        if ((height & 1) == 0) {
            memcpy(cb, cb - 8, 8);
            memcpy(cr, cr - 8, 8);
            cb += 8;
            cr += 8;
        }
    }
    return 0;
}