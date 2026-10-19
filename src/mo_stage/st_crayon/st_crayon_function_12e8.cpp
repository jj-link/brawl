#pragma force_active on
namespace nw4r {
namespace g3d {
class ResMdl {
public:
    const void* GetResNode(unsigned long idx) const;
    void* unk;
};
}
}

struct ResNode {
    char pad[0x2c];
    float x;
    float y;
    float z;
};

struct Obj {
    char pad[0xe8];
    nw4r::g3d::ResMdl mdl;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" {
void fn_56_12E8(void* unused, Vec3* out, Obj* obj, unsigned long idx) {
    nw4r::g3d::ResMdl local;
    local.unk = 0;
    local = obj->mdl;
    if (local.unk) {
        ResNode* node = (ResNode*)local.GetResNode(idx);
        if (node) {
            out->x = node->x;
            out->y = node->y;
            out->z = node->z;
        }
    }
}
}
