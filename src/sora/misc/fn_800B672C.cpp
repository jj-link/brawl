#pragma force_active on
#include <nw4r/g3d/g3d_resmdl.h>

struct ModelData {
    char pad[0xe8];
    nw4r::g3d::ResMdl mdl;
};
struct ModelModule {
    char pad[0x10];
    ModelData* data;
};

inline void getModel(nw4r::g3d::ResMdl* out, ModelData* data) {
    *out = data->mdl;
}

extern "C" void fn_800B672C(ModelModule* self, Vec3f* out, const char* name) {
    ModelData* data = self->data;
    unsigned int storage;
    nw4r::g3d::ResMdl& mdl = *reinterpret_cast<nw4r::g3d::ResMdl*>(&storage);
    getModel(&mdl, data);
    nw4r::g3d::ResNode node = mdl.GetResNode(name);
    out->m_x = node.ref().m_translation.m_x;
    out->m_y = node.ref().m_translation.m_y;
    out->m_z = node.ref().m_translation.m_z;
}
