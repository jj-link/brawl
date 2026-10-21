#include <types.h>
#pragma force_active on

struct Matrix;

class soModelVirtualNode {
public:
    u32 setMatrix(u32 nodeId, Matrix& mtx);
};

class soModelVirtualNodeMgr {
public:
    virtual void vf0();
    virtual soModelVirtualNode* getNode(s32 index);
    virtual void vf2();
    virtual s32 getNodeNum();
};

struct ModelBase {
    u8 pad[8];
};

class soModelModuleImpl : public ModelBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void prepare();

    void setNodeGlobalMtx(u32 nodeId, Matrix* mtx, bool flag);
};

void soModelModuleImpl::setNodeGlobalMtx(u32 nodeId, Matrix* mtx, bool flag) {
    if (!flag) {
        prepare();
    }

    soModelVirtualNodeMgr* mgr =
        *(soModelVirtualNodeMgr**)((u8*)this + 0x90);
    s32 count = mgr->getNodeNum();

    for (s32 i = 0; i < count; i++) {
        soModelVirtualNode* node =
            (*(soModelVirtualNodeMgr**)((u8*)this + 0x90))->getNode(i);
        if (node->setMatrix(nodeId, *mtx) == 1) {
            break;
        }
    }
}
