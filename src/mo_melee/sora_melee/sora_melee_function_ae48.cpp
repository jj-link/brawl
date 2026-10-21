#pragma force_active on

typedef unsigned long u32;

struct Vec3 {
    float x, y, z;
};

struct VirtualNode;

class NodeArray {
public:
    virtual void slot0();
    virtual VirtualNode* at(int);
    virtual void slot2();
    virtual int size() const;
};

struct ModelBase {
    char unused0[8];
};

class Model : public ModelBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void update(u32);

    void* model;
    char unused1[0x80];
    NodeArray* nodes;
};

extern "C" u32 getNodeNum__19soModelModuleSimpleCFv(const Model*);
extern "C" bool getOffset__18soModelVirtualNodeCFUlR5Vec3f(
    const VirtualNode*, u32, Vec3&);
extern "C" Vec3 nwSMGetLocalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(
    const void*, u32);

inline bool isVirtualNode(Model* self, u32 node) {
    if (node >= getNodeNum__19soModelModuleSimpleCFv(self) && node < 300) {
        return true;
    }
    return false;
}

extern "C" Vec3 getNodeLocalPosition__17soModelModuleImplFUlb(
    Model* self, u32 node, bool ready) {
    if (!ready) {
        self->update(node);
    }

    if (isVirtualNode(self, node) == true) {
        int count = self->nodes->size();
        for (int i = 0; i < count; ++i) {
            Vec3 offset;
            if (getOffset__18soModelVirtualNodeCFUlR5Vec3f(
                    self->nodes->at(i), node, offset) == true) {
                return offset;
            }
        }
    }

    return nwSMGetLocalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(
        self->model, node);
}
