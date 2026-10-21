#pragma force_active on

typedef unsigned long u32;

struct ResNodeData {
    char pad[0x14];
    u32 flags;
};

struct ResMdl {
    void* data;
};

struct ScnMdl {
    char pad[0xE8];
    void* resource;
};

struct CopiedVisAccess {
    ScnMdl* model;
    u32 node;
    unsigned char* visibility;
};

struct Ground {
    char pad0[0x44];
    ScnMdl** models;
    char pad48[0x25];
    unsigned char flags;
};

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(ResMdl*);
extern "C" ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const ResMdl*, u32);
extern "C" void __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
    CopiedVisAccess*, ScnMdl*, u32);
extern "C" bool SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
    CopiedVisAccess*, bool);

extern "C" bool setNodeVisibilityAll__6GroundFbUl(
    Ground* self, bool visible, u32 modelIndex)
{
    ResMdl mdl = {0};
    ScnMdl* model = self->models[modelIndex];
    if (!model)
        return false;

    mdl.data = model->resource;
    if (!mdl.data)
        return false;

    u32 i = 0;
    u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&mdl);
    for (; i != count; ++i) {
        ResNodeData* node =
            GetResNode__Q34nw4r3g3d6ResMdlCFUl(&mdl, i);
        if (!node)
            break;

        if ((self->flags >> 7) & 1) {
            CopiedVisAccess access;
            __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
                &access, model, i);
            SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
                &access, visible);
        }

        if (node) {
            if (visible)
                node->flags |= 0x100;
            else
                node->flags &= ~0x100;
        }
    }

    return true;
}
