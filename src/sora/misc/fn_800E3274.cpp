#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct GXColor {
    u8 r, g, b, a;
};

struct CopiedMatAccess {
    u8 data[0x30];
};

struct ResMat {
    u8 pad[0xC];
    u32 id;
};

struct ScnMdl {
    u8 pad[0xE8];
    void* resource;
};

struct Model {
    u8 pad[0xC];
    ScnMdl* scn;
};

extern "C" {
ResMat* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, void*, unsigned long);
void* fn_801AFFDC(void*, bool);
void fn_80191B9C(void*, u32, GXColor*);
void fn_80191AA4(void*, u32, GXColor);
}

extern "C" void fn_800E3274(Model* self, const char* name, int alpha) {
    CopiedMatAccess access;
    GXColor color1;
    GXColor color2;
    ScnMdl* model = self->scn;
    void* resource = 0;
    resource = model->resource;
    ResMat* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&resource, name);
    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
        &access, model, mat->id);
    void* channels = fn_801AFFDC(&access, true);
    fn_80191B9C(&channels, 2, &color1);
    fn_80191B9C(&channels, 3, &color2);
    color1.a = (color1.a * alpha) / 255;
    color2.a = (color2.a * alpha) / 255;
    fn_80191AA4(&channels, 2, color1);
    fn_80191AA4(&channels, 3, color2);
}
