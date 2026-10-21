#pragma force_active on

typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct GXColor {
    u8 r, g, b, a;
};

struct CopiedMatAccess {
    u32 data[13];
};

struct Model {
    u8 pad[0xC];
    void* scn;
};

extern "C" {
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, void*, u32);
void* fn_801AFFDC(void*, bool);
void fn_80191BD4(void*, u32, u8*, s32*, s32*, s32*, s32*, s32*);
void fn_80191AF8(void*, u32, u8, s32, s32, s32, s32, s32);
void fn_80191B9C(void*, u32, GXColor*);
void fn_80191AA4(void*, u32, GXColor);
}

extern "C" void fn_40_42DF8(Model* self, u32 index, s32 alpha) {
    CopiedMatAccess access;
    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
        &access, self->scn, index);
    void* channels = fn_801AFFDC(&access, true);
    u32 channel = 2;

    for (s32 i = 0; i < 2; ++i) {
        s32 source, light, diffuse, attenuation, mask;
        u8 enable;
        GXColor color;

        fn_80191BD4(&channels, channel, &enable, &source, &light,
                    &diffuse, &attenuation, &mask);
        light = 0;
        fn_80191AF8(&channels, channel, enable, source, light,
                    diffuse, attenuation, mask);
        fn_80191B9C(&channels, channel, &color);
        color.a = color.a * alpha / 255;
        fn_80191AA4(&channels, channel, color);
        channel = 3;
    }
}
