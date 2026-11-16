#include <types.h>
#include <so/model/so_model_module_impl.h>
#include <gf/gf_camera.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual soModelVirtualNode* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};
struct ModelData { char pad[0xE8]; void* res; };
struct Layout { char pad0[0xC]; ModelData* model; char pad10[0x80]; Object_vptr_0* nodes; };
extern "C" void OSReport(const char*, ...);
extern "C" void fn_8003DE70(Vec3f*);
extern "C" void fn_8001A194(int, Vec3f*, Vec3f*);
extern char lbl_27_data_4C8[];
extern f32 lbl_27_rodata_308;
static inline bool finiteFloat(f32 f) {
    u32 bits = *(u32*)&f;
    bool result = true;
    if (((bits >> 23) & 0xFF) == 0xFF) result = false;
    return result;
}
static inline bool finiteVec(const Vec3f& v) {
    return finiteFloat(v.m_x) && finiteFloat(v.m_y) && finiteFloat(v.m_z);
}
static inline void setVec(Vec3f& v, f32 z, f32 y, f32 x) {
    v.m_x = x;
    v.m_y = y;
    v.m_z = z;
}
void soModelModuleImpl::renderNodeAxis(u32 arg0, f32 arg1) {
    Matrix mtx(true);
    u32 found;
    Layout* layout = (Layout*)this;
    if (gfCameraManager::getManager() != 0) {
        found = 0;
        for (s32 i = 0; i < layout->nodes->slot3(); i++) {
            if (layout->nodes->slot1(i)->getMatrix(arg0, mtx) == 1) {
                found = 1;
            }
        }
        if (found == 0) {
            u32 exists;
            if (layout->model != 0) {
                nw4r::g3d::ResMdl mdl(layout->model->res);
                if (arg0 >= mdl.GetResNodeNumEntries()) {
                    exists = 0;
                } else {
                    exists = mdl.GetResNode(arg0).IsValid();
                }
            } else {
                exists = 0;
            }
            if (exists == 1) {
                getNodeGlobalMtx(arg0, &mtx, false);
                found = 1;
            }
        }
        if (found == 1) {
            Vec3f org;
            Vec3f c2;
            Vec3f c1;
            Vec3f out;
            f32 oz = mtx.m[2][3], oy = mtx.m[1][3], ox = mtx.m[0][3];
            f32 z2 = mtx.m[2][2], y2 = mtx.m[1][2], x2 = mtx.m[0][2];
            f32 z1 = mtx.m[2][1], y1 = mtx.m[1][1], x1 = mtx.m[0][1];
            setVec(org, oz, oy, ox);
            setVec(c2, z2, y2, x2);
            setVec(c1, z1, y1, x1);
            if (!finiteVec(c2) || !finiteVec(c1)) {
                OSReport(lbl_27_data_4C8);
            } else {
                fn_8003DE70(&c2);
                fn_8003DE70(&c1);
                if (arg1 >= lbl_27_rodata_308) {
                    fn_8001A194(0, &org, &out);
                }
            }
        }
    }
}