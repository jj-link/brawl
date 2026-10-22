#include <types.h>
#pragma force_active on

struct soModelVirtualNode;

struct VNodeArray {
    virtual void unk0();
    virtual soModelVirtualNode* at(s32 index);
    virtual const soModelVirtualNode* at(s32 index) const;
    virtual s32 size() const;
};

extern "C" void init__18soModelVirtualNodeFUlUlP18UnkVirtualNodeInfoP6Matrix(void* this_, u32 start, u32 end, void* info, void* mtxs);

struct soModelModuleImpl {
    char pad[0x90];
    VNodeArray* m_virtualNodes;
};

extern "C" void initVirtualNode__17soModelModuleImplFiUlUlPvP6Matrix(soModelModuleImpl* self, int index, u32 arg1, u32 arg2, void* info, void* mtxs) {
    if (index >= 0) {
        if (index < self->m_virtualNodes->size()) {
            init__18soModelVirtualNodeFUlUlP18UnkVirtualNodeInfoP6Matrix(self->m_virtualNodes->at(index), arg1, arg2, info, mtxs);
        }
    }
}
