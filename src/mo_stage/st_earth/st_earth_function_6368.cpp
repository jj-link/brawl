#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on
extern "C" const float lbl_66_rodata_138;
struct Obj {
    char pad0[0x44];
    nw4r::g3d::ScnMdlSimple** models;
    char pad48[0x78];
    unsigned int index;
    unsigned int node;
    char padc8[0xbc];
    Vec3f* offset;
};
extern "C" void fn_66_6368(Obj* obj, Vec3f* out, unsigned int mode) {
    if (out) {
        out->m_x = lbl_66_rodata_138;
        out->m_y = lbl_66_rodata_138;
        out->m_z = lbl_66_rodata_138;
        bool valid;
        if (obj->index != 0xffffffff && obj->node != 0xffffffff)
            valid = true;
        else
            valid = false;
        if (valid) {
            nw4r::g3d::ScnMdlSimple* model = obj->models[obj->index];
            if (model) {
                nw4r::math::MTX34 mtx;
                if (model->GetScnMtxPos(&mtx, (nw4r::g3d::ScnObj::ScnObjMtxType)1, obj->node)) {
                    Vec3f origin(lbl_66_rodata_138, lbl_66_rodata_138, lbl_66_rodata_138);
                    Vec3f result;
                    ((Matrix*)&mtx)->mulPos(&origin, &result);
                    float x, y, z;
                    z = result.m_z;
                    y = result.m_y;
                    x = result.m_x;
                    out->m_x = x;
                    out->m_y = y;
                    out->m_z = z;
                    if (mode == 1) {
                        out->m_x = x - obj->offset->m_x;
                        out->m_y = y - obj->offset->m_y;
                        out->m_z = z - obj->offset->m_z;
                    }
                }
            }
        }
    }
}