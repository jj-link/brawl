#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/MTX/mtx.h>

#pragma force_active on

// Previous checker result: 99.3% match.

extern "C" {
extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_10;
extern const float lbl_90_rodata_3C;
extern const float lbl_90_rodata_6C;
extern const float lbl_90_rodata_C;
extern const float lbl_90_rodata_F8;
extern const float lbl_90_rodata_FC;
extern const float lbl_90_rodata_108;
extern const float lbl_90_rodata_11C;
extern const float lbl_90_rodata_120;

double sin(float);
void fn_801EC158(void*, float);
void fn_801EC1B8(void*, void*, void*);
void fn_801EC8DC(void*, void*, float, float, float);
void fn_801F2FB0(void*, int);
void fn_801F51DC(const void*, unsigned int);
void fn_801F52E4(int);
}

static inline void drawQuad(unsigned char* tex, float* pos, unsigned int color)
{
    int i;
    unsigned int drawColor;
    float bottom;
    float top;
    float right;
    float left;
    int h;
    int w;

    if (*(int*)(tex + 0x34) == 0)
        return;
    if (*(int*)(tex + 0x34) != 0)
        fn_801F2FB0(tex + 0x14, 0);
    if (color == 0)
        color = *(unsigned int*)(tex + 0x0C);
    if (*(int*)(tex + 0x34) == 0)
        return;

    w = *(int*)(tex + 0x44);
    h = *(int*)(tex + 0x48);
    left = pos[0] - (float)(w >> 1);
    right = left + (float)w;
    top = pos[1] + (float)(h >> 1);
    bottom = top - (float)h;
    float z = pos[2];

    drawColor = 0xFFFFFFFFu;
    for (i = 0; i < 3; ++i) {
        switch (i) {
        case 0:
            GXSetBlendMode((GXBlendMode)3, (GXBlendFactor)4, (GXBlendFactor)1, (GXLogicOp)0xF);
            break;
        case 1:
            left -= lbl_90_rodata_10;
            right += lbl_90_rodata_10;
            top += lbl_90_rodata_10;
            bottom -= lbl_90_rodata_10;
            break;
        case 2:
            GXSetBlendMode((GXBlendMode)1, (GXBlendFactor)4, (GXBlendFactor)1, (GXLogicOp)0xF);
            drawColor = color;
            break;
        }
        GXBegin((_GXPrimitive)0x80, (_GXVtxFmt)0, 4);
        WGPIPE.f = left;  WGPIPE.f = top;    WGPIPE.f = z; WGPIPE.ui = drawColor; WGPIPE.us = 0;      WGPIPE.us = 0;
        WGPIPE.f = right; WGPIPE.f = top;    WGPIPE.f = z; WGPIPE.ui = drawColor; WGPIPE.us = 0x8000; WGPIPE.us = 0;
        WGPIPE.f = right; WGPIPE.f = bottom; WGPIPE.f = z; WGPIPE.ui = drawColor; WGPIPE.us = 0x8000; WGPIPE.us = 0x8000;
        WGPIPE.f = left;  WGPIPE.f = bottom; WGPIPE.f = z; WGPIPE.ui = drawColor; WGPIPE.us = 0;      WGPIPE.us = 0x8000;
        if (i == 1) {
            left += lbl_90_rodata_10;
            right -= lbl_90_rodata_10;
            top -= lbl_90_rodata_10;
            bottom += lbl_90_rodata_10;
        }
    }
}

extern "C" void fn_90_649C(void* arg0, void* arg1)
{
    Mtx m50;
    Mtx m20;
    float pos[3];
    float scale[3];
    unsigned char* self;
    float f;
    float one;
    float fz;
    int mode;

    self = (unsigned char*)arg0;

    if (*(void**)(self + 0x90) == 0)
        return;

    f = *(float*)(self + 0x0C);
    if (f > lbl_90_rodata_6C || f < lbl_90_rodata_F8)
        return;

    one = lbl_90_rodata_0;
    mode = 0;
    if (*(unsigned int*)(self + 0xA4) & 0x800) {
        one = lbl_90_rodata_FC * *(float*)(self + 0xDC);
        if (one >= lbl_90_rodata_10)
            one = lbl_90_rodata_10;
        mode = 1;
    }

    fn_801EC1B8(arg1, self + 0x5C, m50);
    fn_801F51DC(m50, 0);
    fn_801F52E4(0);

    pos[0] = lbl_90_rodata_0;
    pos[1] = lbl_90_rodata_0;
    pos[2] = lbl_90_rodata_0;

    if (mode == 0) {
        drawQuad(*(unsigned char**)(self + 0x90), pos, 0);
        return;
    }

    drawQuad(*(unsigned char**)(self + 0x90), pos,
             ((unsigned int)(lbl_90_rodata_3C * one) + 0x0F) | 0xFF808000u);

    fz = pos[2];
    pos[2] = fz + lbl_90_rodata_C;
    fn_801EC158(m20, fz);

    f = lbl_90_rodata_10 + lbl_90_rodata_11C * (float)sin(lbl_90_rodata_108 * one);
    scale[2] = f;
    scale[1] = f;
    scale[0] = f;
    fn_801EC8DC(m20, m20, scale[0], scale[1], scale[2]);
    fn_801EC1B8(m50, m20, m20);
    fn_801F51DC(m20, 0);

    drawQuad(*(unsigned char**)(self + 0x90), pos,
             ((unsigned int)(lbl_90_rodata_120 * (lbl_90_rodata_10 - one)) + 3) | 0xFF808000u);
}
