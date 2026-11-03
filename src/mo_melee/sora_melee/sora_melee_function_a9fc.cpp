#pragma force_active on
#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <so/model/so_model_module_impl.h>
#include <so/model/so_model_virtual_node.h>

extern "C" void fn_8003E828(Matrix* a, const Vec3f* b, Matrix* out);
extern const f32 lbl_27_rodata_300;

struct Class_NullPad8 {
    char pad[0x8];
};

class Class_Nullable : public Class_NullPad8 {
public:
    virtual void isNull();  // offset 0x8
    virtual void slot1();   // offset 0xc
    virtual void slot2();   // offset 0x10
    virtual void slot3();   // offset 0x14
};

class soModelVirtualNodeMgr {
public:
    virtual void vf0();
    virtual soModelVirtualNode* getNode(s32 index);
    virtual void vf2();
    virtual s32 getNodeNum();
};

void soModelModuleImpl::getNodeGlobalMtx(u32 nodeId, Matrix* mtx, bool flag) const {
    if (!flag) {
        ((Class_Nullable*)this)->slot3();
    }
    if (nodeId >= soModelModuleSimple::getNodeNum()) {
        s32 count = (*(soModelVirtualNodeMgr**)((char*)this + 0x90))->getNodeNum();
        for (s32 i = 0; i < count; i++) {
            soModelVirtualNode* node = (*(soModelVirtualNodeMgr**)((char*)this + 0x90))->getNode(i);
            if (node->getMatrix(nodeId, *mtx) == 1) {
                return;
            }
        }
    }
    soModelModuleSimple::getNodeGlobalMtx(nodeId, mtx, flag);
    if (*((char*)this + 0xC2) == 1) {
        Vec3f* arr = *(Vec3f**)((char*)this + 0xAC);
        Vec3f v = arr[nodeId];
        if (lbl_27_rodata_300 != v.m_x || lbl_27_rodata_300 != v.m_y || lbl_27_rodata_300 != v.m_z) {
            Vec3f tmp;
            tmp = v;
            fn_8003E828(mtx, &tmp, mtx);
        }
    }
}
