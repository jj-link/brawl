#pragma force_active on

typedef unsigned long u32;
typedef unsigned char u8;

struct GXColor {
    u8 r, g, b, a;
};

struct CopiedMatAccess {
    u8 data[0x30];
};

struct Model {
    u8 pad[0xE8];
    void* resource;
};

struct Ground {
    u8 pad[0x44];
    Model** models;
};

extern "C" {
extern const char* const lbl_27_data_54850;
extern const char* const lbl_27_data_54878;

int strcmp(const char*, const char*);
u32 fn_8018F394(void*);
void* fn_8018F340(void*, u32);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, void*, u32);
void* fn_801AFFDC(void*, bool);
void fn_80191AA4(void*, u32, GXColor);
}

inline bool copiedType(const char* a, const char* b)
{
    return strcmp(a, b) == 0;
}

extern "C" void setMatAlpha__6GroundFUlUl(
    Ground* self, u32 alpha, u32 index)
{
    void* resource = 0;
    GXColor color = {0, 0, 0, 0};
    Model* model = self->models[index];
    color.a = (u8)alpha;

    if (model) {
        resource = model->resource;
        u32 i = 0;
        u32 count = fn_8018F394(&resource);

        for (; i != count; ++i) {
            void* channels = 0;

            if (copiedType(lbl_27_data_54850, lbl_27_data_54878)) {
                CopiedMatAccess access;
                __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
                    &access, model, i);
                channels = fn_801AFFDC(&access, true);
            } else {
                channels = (u8*)fn_8018F340(&resource, i) + 0x3EC;
            }

            fn_80191AA4(&channels, 2, color);
        }
    }
}
