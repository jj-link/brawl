#include <types.h>
#pragma force_active on

u8* fn_801DCA78(const char* msg, u32* image, s32 pos, s32 stride, s32* width);

void fn_801DB3C8(u8* fb, u16 width, u16 height, const u8* msgYUV, s32 x, s32 y, u32 lf,
                 const char* msg)
{
    u32 texel[70];
    u32 charWidth;
    u8* tmp;
    u8 bright;
    s32 xPos;
    u32 idx;
    u32 idx2;
    u32 idx3;
    u32 i;
    u32 j;

new_line:
    if (height - 24 < y)
        return;

    tmp = fb + ((x + (y * width)) * 2);
    xPos = x;

    while (*msg != 0) {
        if (*msg == '\n') {
            msg++;
            y += lf;
            goto new_line;
        } else if (width - 48 < xPos) {
            y += lf;
            goto new_line;
        }

        for (i = 0; i < 24; i++) {
            idx = (i & 7) + ((i / 8) * 24);
            texel[idx] = 0;
            texel[idx + 8] = 0;
            texel[idx + 16] = 0;
        }

        msg = (const char*)fn_801DCA78(msg, texel, 0, 6, (s32*)&charWidth);

        for (i = 0; i < 24; i++) {
            idx = (i & 7) + ((i / 8) * 24);
            for (j = 0; j < 24; j++) {
                idx2 = idx + ((j / 8) * 8);
                bright = (texel[idx2] >> ((7 - (j & 7)) * 4)) & 0x0F;
                if (bright != 0) {
                    bright = (((msgYUV[0] * (bright * 0xEF)) / 255) / 15) + 16;
                    idx3 = j + (width * i);
                    tmp[idx3 * 2] = bright;
                    if ((xPos + j) % 2 != 0) {
                        tmp[(idx3 * 2) - 1] = msgYUV[1];
                        tmp[(idx3 * 2) + 1] = msgYUV[2];
                    } else {
                        tmp[(idx3 * 2) - 1] = msgYUV[2];
                        tmp[(idx3 * 2) + 1] = msgYUV[1];
                    }
                }
            }
        }

        tmp += charWidth * 2;
        xPos += charWidth;
    }
}
