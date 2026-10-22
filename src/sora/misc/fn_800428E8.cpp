#pragma force_active on
typedef float f32;
class gfCamera;
class gfCameraManager {
public:
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
};

extern "C" gfCameraManager* getManager__15gfCameraManagerFv(gfCameraManager* self);
extern "C" gfCameraManager* setGX__8gfCameraFv(gfCamera* self);
extern f32 lbl_805A17A8;

extern "C" void fn_800428E8(gfCameraManager* arg0) {
    char buf[0x268];
    f32 k, x0, x4, x8, xc, x10, x14;
    gfCameraManager* t;

    t = setGX__8gfCameraFv((gfCamera*)getManager__15gfCameraManagerFv(arg0));
    k = lbl_805A17A8;
    x4 = arg0->unk4;
    x0 = arg0->unk0;
    xc = arg0->unkC;
    x8 = arg0->unk8;
    x14 = arg0->unk14;
    x10 = arg0->unk10;
    *(f32*)(buf + 0x24) = x0;
    *(f32*)(buf + 0x28) = x4;
    *(f32*)(buf + 0x2C) = k;
    *(f32*)(buf + 0x240) = x0;
    *(f32*)(buf + 0x34) = x4;
    *(f32*)(buf + 0x68) = k;
    *(f32*)(buf + 0x18) = x8;
    *(f32*)(buf + 0x1C) = xc;
    *(f32*)(buf + 0x20) = k;
    *(f32*)(buf + 0x9C) = x8;
    *(f32*)(buf + 0xD0) = xc;
    *(f32*)(buf + 0x104) = k;
    *(f32*)(buf + 0xC) = x10;
    *(f32*)(buf + 0x10) = x14;
    *(f32*)(buf + 0x14) = k;
    *(f32*)(buf + 0x138) = x10;
    *(f32*)(buf + 0x16C) = x14;
    *(f32*)(buf + 0x1A0) = k;
    *(f32*)(buf + 0x0) = x0;
    *(f32*)(buf + 0x4) = x4;
    *(f32*)(buf + 0x8) = k;
    *(f32*)(buf + 0x1D4) = x0;
    *(f32*)(buf + 0x208) = x4;
    *(f32*)(buf + 0x23C) = k;
    getManager__15gfCameraManagerFv(t);
}
