#include <nw4r/g3d/g3d_scnmdl.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern unsigned char lbl_8040ABD8[];
extern "C" void GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(void*, u32, GXColor*);
extern "C" void fn_80190A3C(void*, bool);

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

extern "C" void fn_27_26C78C(Ground* self, const u32* slot, const char* name, const u8* col, const u32* idx) {
    nw4r::g3d::ScnMdl* model = castModel(self->models[*idx]);
    nw4r::g3d::ResMat mat;
    if (model) {
        if (getMaterial(model, name, &mat)) {
            MaterialAccess access(model, mat->m_id);
            nw4r::g3d::ResMatTevColor tev = access.access.GetResMatTevColor(false);
            GXColor copy = {col[0], col[1], col[2], col[3]};
            GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(&tev, *slot, &copy);
            fn_80190A3C(&tev, false);
            mat.DCStore(false);
        }
    }
}
