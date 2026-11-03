#include <so/model/so_model_module_impl.h>
#pragma force_active on

class NodeArray {
public:
    virtual void slot0();
    virtual soModelVirtualNode* at(int);
    virtual void slot2();
    virtual int size() const;
};

extern "C" void fn_27_973C(soModelModuleImpl*);
extern "C" void fn_80047AE0(void*, void*, u32*, int);
extern "C" void fn_800471A4(void*, int, int, void*, void*, int, int, int);

struct Entry {
    int index;
    u32 parent;
};

inline bool isVirtualNode(soModelModuleImpl* self, u32 node) {
    if (node >= self->soModelModuleSimple::getNodeNum() && node < 300)
        return true;
    return false;
}

void soModelModuleImpl::setUpMtx(u32* ids, s32 count) {
    if (count == 1) {
        setUpMtx(*ids);
        return;
    }
    u8* self = (u8*)this;
    if (!((self[0xc5] >> 6) & 1) && (int)self[0xc2] != 2) {
    fn_27_973C(this);
    Entry entries[200];
    u32 realNodes[200];
    Entry* entry = entries;
    u32* realNode = realNodes;
    u32 updateParent;
    void* model = *(void**)(self + 0xc);
    u32 node;
    int entryCount = 0;
    int realCount = 0;
    for (int i = 0; i < count; ++i) {
        node = *ids;
        if (isVirtualNode(this, node) == true) {
            u32 parent;
            int j;
            for (j = 0; j < (*(NodeArray**)(self + 0x90))->size(); ++j) {
                if ((*(NodeArray**)(self + 0x90))->at(j)->getNodeParent(node, parent) == true)
                    break;
            }
            node = getRealNodeId(parent);
            entry->index = j;
            entry->parent = parent;
            ++entry;
            ++entryCount;
        }
        if ((*(s8**)(self + 0xa8))[node] != 1)
            { *realNode++ = node; ++realCount; }
        ++ids;
    }
    if (realCount > 0) {
        fn_80047AE0(model, *(void**)(self + 0xa8), realNodes, realCount);
        *(int*)(self + 0x48) = 0;
        fn_800471A4(model, 0, 0, *(void**)(self + 0xa8), *(void**)(self + 0xac), 0, 0, 0);
        self[0xc2] = 1;
        entry = entries;
        for (int i = 0; i < entryCount; ++i) {
            updateParent = entry->parent;
            Vec3f scale = getNodeScale(updateParent);
            (*(NodeArray**)(self + 0x90))->at(entry->index)->updateMatrix(*this, updateParent, scale);
            ++entry;
        }
    }
    }
}