#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern unsigned char lbl_8040ABD8[];
extern "C" void fn_80191314(nw4r::g3d::ResMatTevColor*, u32, u32*);
extern "C" void fn_80190A3C(nw4r::g3d::ResMatTevColor*, bool);

struct Ground {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
};

static inline nw4r::g3d::ScnMdl* castModel(nw4r::g3d::ScnMdl* model) {
    bool found = false;
    if (model) {
        const void* key = lbl_8040ABD8;
        if (model->IsDerivedFrom((int*)&key))
            found = true;
    }
    if (found)
        return model;
    return 0;
}

static inline bool getMaterial(nw4r::g3d::ScnMdl* model, const char* name, nw4r::g3d::ResMat* mat) {
    if (model) {
        nw4r::g3d::ResMdl resource = model->m_resMdl;
        *mat = resource.GetResMat(name);
        return true;
    }
    return false;
}

struct MaterialAccess {
    nw4r::g3d::ScnMdl::CopiedMatAccess access;
    char padding[4];
    MaterialAccess(nw4r::g3d::ScnMdl* model, u32 id) : access(model, id) {}
};

extern "C" u32 fn_27_26C520(Ground* self, const u32* colorID, const char* name, const u32* modelID) {
    u32 color = 0;
    nw4r::g3d::ScnMdl* model = castModel(self->models[*modelID]);
    nw4r::g3d::ResMat mat;
    if (model) {
        if (getMaterial(model, name, &mat)) {
            MaterialAccess copied(model, mat->m_id);
            nw4r::g3d::ResMatTevColor tev = copied.access.GetResMatTevColor(false);
            fn_80191314(&tev, *colorID, &color);
            fn_80190A3C(&tev, false);
            mat.DCStore(false);
            return color;
        }
    }
    return color;
}
