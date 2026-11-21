#include <nw4r/g3d/g3d_scnmdl.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

struct MatAccess : nw4r::g3d::ScnMdl::CopiedMatAccess {
    u8 padding[4];

    MatAccess(nw4r::g3d::ScnMdl* model, u32 index)
        : nw4r::g3d::ScnMdl::CopiedMatAccess(model, index) {}
};

struct Material {
    char pad[12];
    u32 id;
};

struct Model {
    char pad[12];
    nw4r::g3d::ScnMdl* scn;
};

struct Title {
    char pad[0x50];
    Model* model;
    char pad2[12];
    float alpha;
    float value;
    char pad3[0x10];
    int state;
};

extern "C" {
u32 fn_8018F394(void*);
Material* fn_8018F2EC(void*, u32);
void* fn_801B01BC(void*);
void fn_80191B9C(void*, u32, GXColor*);
void fn_80191AA4(void*, u32, GXColor*);
void fn_24_2600(Title*, float);
}

extern "C" void fn_24_1D40(Title* self) {
    if (self->state != 0 && self->state != 0x12 && self->state != 0x13) {
        u32 i;
        u32 copyBits;
        GXColor color;
        void* channels;
        void* resource = (char*)self->model + 8;
        float alpha = self->alpha;
        u32 count = fn_8018F394(resource);

        for (i = 0; i < count; ++i) {
            nw4r::g3d::ScnMdl* scn = self->model->scn;
            Material* material = fn_8018F2EC(resource, i);
            MatAccess access(scn, material->id);
            channels = fn_801B01BC(&access);
            fn_80191B9C(&channels, 2, &color);
            color.a = (u8)(int)(color.a * alpha);
            copyBits = *(u32*)&color;
            fn_80191AA4(&channels, 2, (GXColor*)&copyBits);
        }

        fn_24_2600(self, self->value);
    }
}
