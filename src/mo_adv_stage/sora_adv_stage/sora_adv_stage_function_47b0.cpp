#pragma force_active on
typedef unsigned short u16;

enum ARCNodeType { ARC_NODE_TYPE_DUMMY = 0 };

class gfArchive {
public:
    void* getData(ARCNodeType type, int id, u16 index);
};

struct Vec3 {
    float x;
    float y;
    float z;
};

struct ResNodeData {
    char pad[0x38];
    float x;
    float y;
    float z;
};

namespace nw4r {
namespace g3d {
class ResMdl {
public:
    void* m_p;
    ResNodeData* GetResNode(int idx) const;
};
}
}

struct Owner {
    char pad[0x1a0];
    gfArchive* archive;
};

extern "C" void* fn_8018D174(void* p, int idx);

extern "C" void fn_40_47B0(Owner* self, Vec3* out, int unk) {
    void* p = self->archive->getData((ARCNodeType)2, unk, 0xFFFE);
    nw4r::g3d::ResMdl mdl;
    mdl.m_p = fn_8018D174(&p, 0);
    ResNodeData* n = mdl.GetResNode(1);
    out->x = n->x;
    out->y = n->y;
    out->z = n->z;
}
