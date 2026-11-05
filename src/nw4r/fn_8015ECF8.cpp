#include <nw4r/ut/ut_Color.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual int fn_801AB290();
};

struct RenderState {
    GXColor first;
    GXColor second;
    u8 padding[0x40];
    Class_8042B6D0* object;
};

extern "C" {
extern u32 lbl_8049EDA0[4];
extern signed char lbl_805A04A8;
extern u8 lbl_805A04AC;
extern u8 lbl_805A04AD;
extern u8 lbl_805A04AE;
extern u8 lbl_805A04AF;
extern u8 lbl_8049ED90[];
extern const float lbl_805A2BB8;
void* __dt__Q34nw4r2ut5ColorFv(void*, int);
void __register_global_object(void*, void*, void*);
void fn_8015FE30(const GXColor*, const GXColor*);
void fn_801F3F5C(int, int, int, int, int);
void fn_801F4010(int, int, int);
void fn_801F3AFC(int);
void fn_801F3F20(int, int, int);
void fn_801F3C30(int, int, int, int, int);
void fn_801F3C70(int, int, int, int, int);
void fn_801F3CB0(int, int, int, int, int, int);
void fn_801F3D08(int, int, int, int, int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801EFB10();
void fn_801EF280(int, int);
}

#define INIT_FOG() \
    if (lbl_805A04A8 == 0) { \
        *(u32*)&lbl_805A04AC = 0; \
        __register_global_object(&lbl_805A04AC, (void*)__dt__Q34nw4r2ut5ColorFv, lbl_8049ED90); \
        lbl_805A04A8 = 1; \
    } \
    { GXColor color; \
    u8* p = &lbl_805A04AC; \
    color.r = *p++; \
    color.g = lbl_805A04AD; \
    color.b = lbl_805A04AE; \
    color.a = lbl_805A04AF; \
    typedef void (*FogFunction)(GXFogType, const GXColor*, float, float, float, float); \
    ((FogFunction)GXSetFog)(GX_FOG_NONE, &color, lbl_805A2BB8, lbl_805A2BB8, lbl_805A2BB8, lbl_805A2BB8); }

#define SETUP() \
    fn_801F3F5C(0, 0, 1, 2, 3); \
    fn_801F4010(0, 17, 0); \
    GXSetNumChans(1); \
    GXSetChanCtrl(GX_COLOR0A0, 0, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE); \
    GXSetChanCtrl(GX_COLOR1A1, 0, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE); \
    GXSetNumTexGens(1); \
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 60, 0, 125); \
    GXSetNumIndStages(0); \
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET); \
    GXSetNumTevStages(1); \
    fn_801F3AFC(0); \
    fn_801F3F20(0, 0, 0); \
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0)

#define VERTICES() \
    fn_801EFB44(0, 9, 1, 4, 0); \
    fn_801EFB44(0, 11, 1, 5, 0); \
    fn_801EFB44(0, 13, 1, 2, 15); \
    fn_801EFB10(); \
    fn_801EF280(9, 1); \
    fn_801EF280(11, 1); \
    fn_801EF280(13, 1)

extern "C" void fn_8015ECF8(RenderState* state) {
    lbl_8049EDA0[0] = 255;
    lbl_8049EDA0[1] = 0;
    if (*(u32*)&state->first != 0 || *(u32*)&state->second != 0xFFFFFFFF) {
        GXColor first = state->first;
        GXColor second = state->second;
        fn_8015FE30(&first, &second);
    } else if (state->object) {
        switch (state->object->fn_801AB290()) {
        case 0:
        case 1:
            INIT_FOG();
            SETUP();
            fn_801F3C30(0, 15, 15, 15, 10);
            fn_801F3C70(0, 7, 4, 5, 7);
            fn_801F3CB0(0, 0, 0, 0, 1, 0);
            fn_801F3D08(0, 0, 0, 0, 1, 0);
            VERTICES();
            break;
        case 2:
        case 3:
            INIT_FOG();
            SETUP();
            GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
            VERTICES();
            break;
        case 4:
        case 5:
        case 6:
            INIT_FOG();
            SETUP();
            GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
            VERTICES();
            break;
        default:
            INIT_FOG();
            SETUP();
            GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
            VERTICES();
            break;
        }
    } else {
        INIT_FOG();
        SETUP();
        GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
        VERTICES();
    }
}
