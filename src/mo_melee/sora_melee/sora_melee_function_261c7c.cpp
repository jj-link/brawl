#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct ScnMdl {
    u8 pad[0xE8];
    void* resource;
};

struct Owner {
    u8 pad0[0x44];
    ScnMdl** models;
    u8 pad1[0x10];
    u32 count;
    u8 pad2[0x11];
    u8 flags;
};

struct CopiedMatAccess {
    u8 data[0x34];
};

struct MaterialInfo {
    u8 pad[0xC];
    u8 count;
};

extern "C" {
u32 fn_8018F394(void*);
void* fn_8018F340(void*, u32);
MaterialInfo* fn_801923B0(void*);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
    void*, ScnMdl*, unsigned long);
void* fn_801B0024(void*, int);
void fn_801910C8(void*, u8);
}

extern "C" void fn_27_261C7C(Owner* self)
{
    if ((self->flags >> 2) & 1) {
        self->flags &= ~2;
        if (self->models) {
            u32 count = self->count;
            for (u32 i = 0; i != count; ++i) {
                ScnMdl* model = self->models[i];
                void* resource = model->resource;
                u32 materialCount = fn_8018F394(&resource);

                for (u32 j = 0; j < materialCount; ++j) {
                    void* result;
                    void* material = fn_8018F340(&resource, j);
                    u8 n = fn_801923B0(&material)->count;
                    CopiedMatAccess access;
                    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
                        &access, model, j);
                    result = fn_801B0024(&access, 0);
                    if ((int)n > 1) {
                        fn_801910C8(&result, (u8)(n - 1));
                    }
                }
            }
        }
    }
}
