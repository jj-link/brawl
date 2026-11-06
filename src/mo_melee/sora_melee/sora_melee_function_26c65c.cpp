#include <nw4r/g3d/g3d_scnmdl.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern unsigned char lbl_8040ABD8[];
extern "C" void* fn_801AFFDC(void*, bool);
extern "C" void fn_80191AA4(void*, u32, GXColor*);

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

extern "C" void fn_27_26C65C(Ground* self, const u32* colorID, const char* name, const GXColor* color, const u32* modelID) {
    nw4r::g3d::ScnMdl* model = castModel(self->models[*modelID]);
    nw4r::g3d::ResMat mat;
    if (model) {
        if (getMaterial(model, name, &mat)) {
            MaterialAccess access(model, mat->m_id);
            void* channels = fn_801AFFDC(&access, false);
            GXColor copy = *color;
            fn_80191AA4(&channels, *colorID, &copy);
            mat.DCStore(false);
        }
    }
}
