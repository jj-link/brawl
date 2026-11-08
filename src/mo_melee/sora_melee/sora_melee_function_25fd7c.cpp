#pragma force_active on

#include <nw4r/g3d/g3d_scnmdl.h>

typedef unsigned char u8;

struct Model {
    u8 pad[0xE8];
    u8* resource;
};

struct Ground {
    u8 pad[0x44];
    Model** models;
};

struct MatAccess : nw4r::g3d::ScnMdl::CopiedMatAccess {
    u8 padding[8];

    MatAccess(nw4r::g3d::ScnMdl* model, u32 index)
        : nw4r::g3d::ScnMdl::CopiedMatAccess(model, index) {}
};

extern "C" {
extern const char* const lbl_27_data_54850;
extern const char* const lbl_27_data_54878;
extern const float lbl_27_rodata_42A8;

int strcmp(const char*, const char*);
u32 fn_8018F394(void*);
void* fn_8018F340(void*, u32);
void* fn_801AFFDC(void*, bool);
void fn_80191B9C(void*, u32, GXColor*);
void fn_80191AA4(void*, u32, GXColor);
}

inline bool copiedType(const char* a, const char* b)
{
    return strcmp(a, b) == 0;
}

extern "C" void setMatAlphaMul__6GroundFUlUl(
    Ground* self, u32 alphaMul, u32 index)
{
    u32 multiplier = alphaMul;
    u8* resource = 0;
    Model* model = self->models[index];

    if (model) {
        resource = model->resource;
        u32 i = 0;
        u32 count = fn_8018F394(&resource);

        for (; i != count; ++i) {
            GXColor color;
            void* channels = 0;

            if (copiedType(lbl_27_data_54850, lbl_27_data_54878)) {
                MatAccess access((nw4r::g3d::ScnMdl*)model, i);
                channels = fn_801AFFDC(&access, true);
            } else {
                channels = (u8*)fn_8018F340(&resource, i) + 0x3EC;
            }

            fn_80191B9C(&channels, 2, &color);
            float a = color.a, b = multiplier;
            color.a = (u8)(int)(a * b / lbl_27_rodata_42A8);
            fn_80191AA4(&channels, 2, color);
        }
    }
}
