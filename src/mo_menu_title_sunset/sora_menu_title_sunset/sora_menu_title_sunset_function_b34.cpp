#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct GXColor {
    u8 r, g, b, a;
};

struct CopiedMatAccess {
    u8 data[0x34];
};

struct ResMat {
    u8 pad[0xc];
    u32 id;
};

struct Model {
    u8 pad[0xc];
    void* scn;
};

struct Parameters {
    u8 pad[0x1c];
    float alpha;
};

struct Sunset {
    u8 pad0[0x60];
    Model** models;
    u8 pad1[0x14];
    Parameters* parameters;
};

extern "C" {
extern const float lbl_25_rodata_18;
u32 fn_8018F394(void*);
ResMat* fn_8018F2EC(void*, u32);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, void*, unsigned long);
void* fn_801B01BC(void*);
void fn_80191B9C(void*, u32, GXColor*);
void fn_80191AA4(void*, u32, GXColor);
}

extern "C" void fn_25_B34(Sunset* self, u32 index, float alpha) {
    self->parameters[index].alpha = alpha;
    void* model;
    u32 modelOffset = index * 4;
    void* resource = (u8*)(*(Model**)((u8*)self->models + modelOffset)) + 8;
    u32 count = fn_8018F394(resource);

    for (u32 i = 0; i < count; ++i) {
        model = (*(Model**)(modelOffset + (u32)self->models))->scn;
        ResMat* material = fn_8018F2EC(resource, i);
        CopiedMatAccess access;
        __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
            &access, model, material->id);
        void* channels = fn_801B01BC(&access);
        GXColor color;
        fn_80191B9C(&channels, 2, &color);
        color.a = (u8)(int)(lbl_25_rodata_18 * alpha);
        fn_80191AA4(&channels, 2, color);
    }
}
