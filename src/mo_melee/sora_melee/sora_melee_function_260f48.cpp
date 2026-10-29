#include <types.h>
#pragma force_active on

struct MTX34 {
    float m[3][4];
};

struct ScnMdlSimple {
    char pad[0xE8];
    void* resource;
};

class Ground {
    char pad[0x44];
public:
    ScnMdlSimple** models;
};

extern "C" {
void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);
s32 GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    ScnMdlSimple*, MTX34*, int, u32);

s32 getNodeMatrix__6GroundFP6MatrixUlPCc(Ground* self, MTX34* matrix, u32 index, const char* name) {
    s32 ok;
    s32 nodeId;
    if (name == 0) {
        ok = 0;
    } else {
        void* local = 0;
        ScnMdlSimple* model = self->models[index];
        if (model == 0) {
            ok = 0;
        } else {
            local = model->resource;
            if (local == 0) {
                ok = 0;
            } else {
                void* res = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, name);
                if (res == 0) {
                    ok = 0;
                } else {
                    if (res != 0) {
                        nodeId = *(s32*)((char*)res + 0xc);
                    } else {
                        nodeId = 0;
                    }
                    ok = 1;
                }
            }
        }
    }
    if (ok == 0) {
        return 0;
    }
    return GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
        self->models[index], matrix, 1, (u32)nodeId);
}
}
