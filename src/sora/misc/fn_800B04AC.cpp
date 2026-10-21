#pragma force_active on

typedef unsigned int u32;

struct Model {
    u32 flags;
    u32 unknown;
    void* resource;
    void* sceneModel;
};

struct VisibilityNode {
    VisibilityNode* next;
    u32 unknown;
    Model* model;
    u32 index;
    unsigned char visible;
};

struct Object {
    char pad0[0x50];
    Model** models;
    u32 count;
    char pad58[0x148];
    VisibilityNode* nodes;
};

struct CopiedVisAccess {
    void* model;
    u32 index;
    unsigned char* visibility;
};

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
extern "C" void __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
    CopiedVisAccess*, void*, u32);
extern "C" bool SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
    CopiedVisAccess*, bool);

extern "C" void fn_800B04AC(Object* self) {
    if (self->models) {
        u32 j;
        u32 offset;
        u32 i = 0;
        offset = 0;
        for (; i < self->count; ++i) {
            Model* model = *(Model**)((char*)self->models + offset);
            if (model && !(model->flags >> 31)) {
                u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(
                    &model->resource);
                for (j = 0; j < count; ++j) {
                    CopiedVisAccess access;
                    __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
                        &access, model->sceneModel, j);
                    SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
                        &access, false);
                }
            }
            offset += 4;
        }
    }

    for (VisibilityNode* node = self->nodes; node; node = node->next) {
        if (!node->visible) {
            CopiedVisAccess access;
            __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
                &access, node->model->sceneModel, node->index);
            SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
                &access, false);
        }
    }
}
