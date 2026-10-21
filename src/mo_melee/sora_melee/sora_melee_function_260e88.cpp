#include <types.h>
#pragma force_active on

class Matrix;

extern "C" void setIdentity__6MatrixFv(void*);
extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
extern "C" s32 GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(void*, void*, int, u32);

class Ground {
public:
    s32 getNodeMatrix(Matrix*, u32, u32);

    char pad0[0x44];
    void** unk44;
};

inline s32 getMatrix(void* node, Matrix* matrix, u32 index, void** mdl) {
    if (GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(mdl) <= index) {
        return 0;
    }
    return GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
        node, matrix, 1, index);
}

s32 Ground::getNodeMatrix(Matrix* arg0, u32 arg1, u32 arg2) {
    s32 result;
    void* sp8;
    void* node;
    u32 count;

    if (arg0 == 0) {
        return 0;
    }

    setIdentity__6MatrixFv(arg0);
    result = 0;
    sp8 = 0;
    node = unk44[arg1];

    if (node == 0) {
        return 0;
    }

    sp8 = *(void**)((char*)node + 0xE8);
    if (sp8 == 0) {
        return 0;
    }

    result = getMatrix(node, arg0, arg2, &sp8);
    return result;
}
