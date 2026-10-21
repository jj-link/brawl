#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct ResMdl {
    void* data;
};

struct ScnMdlSimple {
    char pad[0xE8];
    void* resource;
};

struct Ground {
    char pad[0x44];
    ScnMdlSimple** models;
};

struct MTX34 {
    float m[3][4];
};

extern "C" {
extern float lbl_27_rodata_42A4;

u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(ResMdl*);

s32 GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    ScnMdlSimple*, MTX34*, int, u32);
}

extern "C" s32 getNodePosition__6GroundFP5Vec3fUlUl(
    Ground* self, Vec3f* out, u32 modelIndex, u32 nodeIndex)
{
    MTX34 matrix;

    if (!out)
        return 0;

    out->set(lbl_27_rodata_42A4, lbl_27_rodata_42A4, lbl_27_rodata_42A4);

    ResMdl mdl = {0};
    ScnMdlSimple* model = self->models[modelIndex];
    if (!model)
        return 0;

    mdl.data = model->resource;
    if (!mdl.data)
        return 0;

    if (GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&mdl) <= nodeIndex)
        return 0;

    if (!GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
            model, &matrix, 1, nodeIndex))
        return 0;

    out->set(matrix.m[0][3], matrix.m[1][3], matrix.m[2][3]);
    return 1;
}
