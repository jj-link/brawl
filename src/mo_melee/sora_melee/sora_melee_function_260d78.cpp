#include <types.h>
#pragma force_active on

struct Vec3f { float x, y, z; };
struct MTX34 { float m[3][4]; };
struct ResMdl { void* data; };
struct ScnMdlSimple { char pad[0xE8]; void* resource; };
struct Ground { char pad[0x44]; ScnMdlSimple** models; };
struct ResNode { char pad[0xc]; u32 index; };

extern "C" ResNode* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(ResMdl*, const char*);
extern "C" s32 GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    ScnMdlSimple*, MTX34*, s32, u32);

extern "C" s32 getNodePosition__6GroundFP5Vec3fUlPCc(
    Ground* self, Vec3f* out, u32 index, const char* name)
{
    MTX34 matrix;
    u32 nodeIndex;
    int b;

    if (name == 0) {
        b = 0;
    } else {
        ResMdl mdl;
        mdl.data = 0;
        ScnMdlSimple* model = self->models[index];
        if (model == 0) {
            b = 0;
        } else {
            mdl.data = model->resource;
            if (mdl.data == 0) {
                b = 0;
            } else {
                ResNode* rn = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&mdl, name);
                if (rn == 0) {
                    b = 0;
                } else {
                    nodeIndex = rn ? rn->index : 0;
                    b = 1;
                }
            }
        }
    }

    if (b == 0)
        return 0;

    if (GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
            self->models[index], &matrix, 1, nodeIndex) == 0)
        return 0;

    float x2, y2, z2;
    z2 = matrix.m[2][3];
    y2 = matrix.m[1][3];
    x2 = matrix.m[0][3];
    out->x = x2;
    out->y = y2;
    out->z = z2;
    return 1;
}
