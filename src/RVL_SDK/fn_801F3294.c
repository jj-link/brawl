#include <revolution/GX/GXInit.h>
#pragma force_active on
extern void fn_801F3204(unsigned int, unsigned int);

void fn_801F3294(void)
{
    unsigned char *p, *q, *g, *g2;
    unsigned int j, n, m, tex, coord, i;

    g = (unsigned char *)__GXData;
    if (*(unsigned int*)(g + 0x5e4) != 0xff) {
        n = ((*(unsigned int*)(g + 0x254) >> 10) & 15) + 1;
        m = (*(unsigned int*)(g + 0x254) >> 16) & 7;
        for (i = 0; i < m; i++) {
            switch (i) {
            case 0:
                tex = *(unsigned int*)(g + 0x170) & 7;
                coord = (*(unsigned int*)(g + 0x170) >> 3) & 7;
                break;
            case 1:
                tex = (*(unsigned int*)(g + 0x170) >> 6) & 7;
                coord = (*(unsigned int*)(g + 0x170) >> 9) & 7;
                break;
            case 2:
                tex = (*(unsigned int*)(g + 0x170) >> 12) & 7;
                coord = (*(unsigned int*)(g + 0x170) >> 15) & 7;
                break;
            case 3:
                tex = (*(unsigned int*)(g + 0x170) >> 18) & 7;
                coord = (*(unsigned int*)(g + 0x170) >> 21) & 7;
                break;
            }
            if (!(*(unsigned int*)(g + 0x5e4) & (1 << coord)))
                fn_801F3204(tex, coord);
        }
        g2 = *(unsigned char **)&__GXData;
        p = g2;
        q = g2 + 0x150;
        for (j = 0; j < n; j++) {
            unsigned int offset = (j >> 1) << 2;
            tex = *(unsigned int*)(p + 0x5a4) & 0xfffffeff;
            if (j & 1)
                coord = (*(unsigned int*)(q + offset) >> 15) & 7;
            else
                coord = (*(unsigned int*)(q + offset) >> 3) & 7;
            if (tex != 0xff &&
                !(*(unsigned int*)(g + 0x5e4) & (1 << coord)) &&
                (*(unsigned int*)(g2 + 0x5e8) & (1 << j)))
                fn_801F3204(tex, coord);
            p += 4;
        }
    }
}
