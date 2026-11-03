#pragma use_lmw_stmw on
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

void *memcpy(void *dst, const void *src, unsigned long n);

typedef struct {
    u8 pad0[0x22];
    u8 countX;
    u8 countY;
    unsigned long offsetX;
    unsigned long offsetY;
    u8 tileSize;
    u8 pad2d[0x48 - 0x2d];
    unsigned long pitch;
    u8 pad4c[0x64 - 0x4c];
    u16 *pixels;
} Fn8026F2CCInput;

static inline u16 getTexel(u16 *source, unsigned long row, int column) {
    return source[(column & 3) + (((column >> 2) + row) * 16)];
}

static inline void unpackPixel(int pixel, u8 *red, u8 *green, u8 *blue) {
    *red = pixel >> 8;
    *green = pixel >> 3;
    *blue = pixel << 3;
    *red &= 0xF8;
    *green &= 0xFC;
    *blue &= 0xF8;
}

int fn_8026F2CC(u8 *output, Fn8026F2CCInput *input, int x, int y) {
    u8 *luma = output + 4;
    u8 *cb = output + 0x104;
    u8 *cr = output + 0x144;
    u16 *pixels = input->pixels;
    u8 red;
    u8 blue;
    int column;
    int width;
    int rowEndX;
    int height;
    int rowEndY;
    int pitch = input->pitch >> 2;
    int i;
    u16 pixel;

    if (input->offsetX == (unsigned long)x) {
        width = input->countX;
    } else {
        width = 0x10 / input->tileSize;
    }

    if (input->offsetY == (unsigned long)y) {
        height = input->countY;
    } else {
        height = 0x10 / input->tileSize;
    }

    rowEndX = x + width;
    rowEndY = y + height;

    for (; y < rowEndY; y++) {
        for (column = x; column < rowEndX; column++) {
            u8 green;

            pixel = getTexel((u16 *)((u8 *)pixels + ((y & 3) * 8)), (unsigned long)((y >> 2) * pitch), column);
            unpackPixel(pixel, &red, &green, &blue);

            *luma = (u8)((red * 0x4D + green * 0x96 + blue * 0x1D + 0x80) >> 8);

            if ((column & 1) == 0 && (y & 1) == 0) {
                *cb = (u8)(((blue - *luma) * 0x90 + 0x80) >> 8);
                cb++;
                *cr = (u8)(((red - *luma) * 0xB7 + 0x80) >> 8);
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
