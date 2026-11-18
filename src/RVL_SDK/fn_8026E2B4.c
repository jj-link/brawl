#pragma use_lmw_stmw on
#include <types.h>
#include <stl/internal/mem.h>
#pragma force_active on
typedef struct {
    u8 pad0[0x22];
    u8 countX, countY;
    unsigned long offsetX, offsetY;
    u8 tileSize;
    u8 pad2d[0x48 - 0x2d];
    unsigned long pitch;
    u8 pad4c[0x64 - 0x4c];
    u16 *pixels;
} Input;
static inline void unpack(u16 *source, unsigned long row, int column, u8 *red, u8 *green, u8 *blue) {
    unsigned long index = (column >> 2) * 2 - (-row);
    u16 pixel2 = source[(column & 3) + ((index + 1) * 16)];
    u16 pixel1 = source[(column & 3) + (index * 16)];
    *green = pixel2 >> 8;
    *blue = pixel2;
    *red = pixel1;
}
int fn_8026E2B4(u8 *output, Input *input, int x, int y) {
    u8 *luma = output + 4;
    u8 *cb = output + 0x104;
    u8 *cr = output + 0x144;
    int row;
    u16 *pixels = input->pixels;
    u16 *source;
    u8 red;
    int column, width, rowEndX, rowEndY, height, i;
    int pitch = (input->pitch >> 1) & 0x7ffffffe;
    if (input->offsetX == (unsigned long)x) width = input->countX;
    else width = 0x20 / input->tileSize;
    if (input->offsetY == (unsigned long)y) height = input->countY;
    else height = 8 / input->tileSize;
    rowEndX = x + width;
    rowEndY = y + height;
    for (; y < rowEndY; y++) {
        source = (u16 *)((u8 *)pixels + ((y & 3) * 8));
        row = (y >> 2) * pitch;
        for (column = x; column < rowEndX; column++) {
            u8 green, blue;
            unpack(source, row, column, &red, &green, &blue);
            *luma = (u8)((red * 0x4d + green * 0x96 + blue * 0x1d + 0x80) >> 8);
            if ((column & 3) == 0) {
                *cb = (u8)(((blue - *luma) * 0x90 + 0x80) >> 8);
                cb++;
                *cr = (u8)(((red - *luma) * 0xb7 + 0x80) >> 8);
                cr++;
            }
            luma++;
        }
        for (i = width; i < 0x20; i++) {
            *luma = luma[-1];
            luma++;
            if ((i & 3) == 0) {
                *cb = cb[-1];
                cb++;
                *cr = cr[-1];
                cr++;
            }
        }
    }
    for (; height < 8; height++) {
        memcpy(luma, luma - 0x20, 0x20);
        luma += 0x20;
        memcpy(cb, cb - 8, 8);
        memcpy(cr, cr - 8, 8);
        cb += 8;
        cr += 8;
    }
    return 0;
}
