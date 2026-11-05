#include <revolution/GX.h>
#pragma force_active on
extern "C" {
void fn_801F256C(int, GXColor);
void fn_801F2494(int, GXColor);
}
struct DrawState {
    unsigned char pad[0xA4];
    int fieldA4;
    int fieldA8;
    unsigned char fieldAC;
    unsigned char fieldAD;
};
struct Lighting {
    unsigned char pad[0x60];
    unsigned char enabled;
    unsigned char pad61[3];
    GXLightID lights;
    unsigned char attenuated;
};
extern "C" void fn_80174E38(DrawState* self, void*, const unsigned char* material, Lighting* lighting) {
    self->fieldA4 = -1;
    self->fieldA8 = -1;
    GXSetNumChans(1);
    if (lighting->enabled && material[0x5C] == 1) {
        GXSetChanCtrl(GX_COLOR0, 1, GX_SRC_REG, GX_SRC_REG, lighting->lights,
                      GX_DF_NONE, lighting->attenuated ? GX_AF_SPOT : GX_AF_NONE);
    } else {
        GXSetChanCtrl(GX_COLOR0, 0, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    }
    GXSetChanCtrl(GX_ALPHA0, 0, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_COLOR1A1, 0, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXColor white, black;
    white.r = white.g = white.b = 255;
    white.a = 255;
    black.r = black.g = black.b = 0;
    black.a = 0;
    fn_801F256C(4, white);
    fn_801F2494(4, black);
    self->fieldAC = 0;
    self->fieldAD = 0;
    for (int i = 0; i < 3; ++i) {
        if (material[0x5D + i] == 1 || material[0x5D + i] == 2) self->fieldAC = 1;
        if (material[0x5D + i] == 1 || material[0x5D + i] == 2) self->fieldAD = 1;
    }
    for (int i = 0; i < 4; ++i) {
        if (material[0x60 + i] == 1 || material[0x60 + i] == 2) self->fieldAC = 1;
        if (material[0x60 + i] == 3 || material[0x60 + i] == 4) self->fieldAD = 1;
    }
}
