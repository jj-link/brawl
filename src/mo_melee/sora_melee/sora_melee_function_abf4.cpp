#include <types.h>
#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on
class soModelModuleSimple { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void update(u32); virtual u32 getNodeNum() const; };
class soModelVirtualNode { public: virtual void slot0(); virtual void* at(s32); virtual void slot2(); virtual s32 size() const; };
struct ModelBase { u8 pad[8]; };
class Model : public ModelBase {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void update(u32);
    nw4r::g3d::ScnMdlSimple* model;
    u8 pad1[0x80];
    soModelVirtualNode* nodes;
};
extern "C" u32 getNodeNum__19soModelModuleSimpleCFv(const soModelModuleSimple*);
extern "C" bool getMatrix__18soModelVirtualNodeCFUlR6Matrix(const void*, u32, Matrix&);
extern "C" void nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(Vec3f*, const nw4r::g3d::ScnMdlSimple*, u32);
inline bool isVirtualNode(const soModelModuleSimple* self, u32 node) {
    if (node >= getNodeNum__19soModelModuleSimpleCFv(self) && node < 300) return true;
    return false;
}
extern "C" void getNodeGlobalPosition__17soModelModuleImplFUlb(Vec3f* out, Model* self, u32 node, bool ready) {
    if (!ready) self->update(node);
    if (isVirtualNode((const soModelModuleSimple*)self, node) == true) {
        s32 count = self->nodes->size();
        for (s32 i = 0; i < count; ++i) {
            Matrix matrix(true);
            if (getMatrix__18soModelVirtualNodeCFUlR6Matrix(self->nodes->at(i), node, matrix) == 1) {
                float z = matrix(2, 3);
                float y = matrix(1, 3);
                float x = matrix(0, 3);
                Vec3f pos;
                pos.m_y = y;
                pos.m_x = x;
                pos.m_z = z;
                u32* dst = (u32*)out;
                u32* src = (u32*)&pos;
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                return;
            }
        }
    }
    nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(out, self->model, node);
}