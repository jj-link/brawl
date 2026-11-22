#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

static inline void getPixel(u16 *source, unsigned long row, int column, u8 *red, u8 *green, u8 *blue) {
    u16 gb = source[(column & 3) + ((((column >> 2) << 1) + row + 1) * 16)];
    u16 ar = source[(column & 3) + ((((column >> 2) << 1) + row) * 16)];
    *red = ar;
    *green = gb >> 8;
    *blue = gb;
}

int fn_8026E104(u8 *output, u8 *input, int x, int y) {
    u16 *pixels = *(u16 **)(input + 0x64);
    u8 *luma = output + 4;
    u8 red;
    u8 blue;
    u8 *cb = output + 0x104;
    u8 *cr = output + 0x144;
    int column;
    int width;
    int rowEndX;
    int rowEndY;
    int pitch = (*(unsigned long *)(input + 0x48) >> 1) & 0x7ffffffe;

    width = 16 / input[0x2c];
    rowEndX = x + width;
    rowEndY = y + width;

    for (; y < rowEndY; y++) {
        for (column = x; column < rowEndX; column += 2) {
            u8 green;
            getPixel((u16 *)((u8 *)pixels + ((y & 3) * 8)), (unsigned long)((y >> 2) * pitch), column, &red, &green, &blue);
            *luma = (u8)((red * 0x4D + green * 0x96 + blue * 0x1D + 0x80) >> 8);
            if ((y & 1) == 0) {
                *cb = (u8)(((blue - *luma) * 0x90 + 0x80) >> 8);
                cb++;
                *cr = (u8)(((red - *luma) * 0xB7 + 0x80) >> 8);
                cr++;
            }
            getPixel((u16 *)((u8 *)pixels + ((y & 3) * 8)), (unsigned long)((y >> 2) * pitch), column + 1, &red, &green, &blue);
            luma[1] = (u8)((red * 0x4D + green * 0x96 + blue * 0x1D + 0x80) >> 8);
            luma += 2;
        }
        luma += 16 - width;
        if ((y & 1) == 0) {
            cb += (16 - width) >> 1;
            cr += (16 - width) >> 1;
        }
    }
    return 0;
}