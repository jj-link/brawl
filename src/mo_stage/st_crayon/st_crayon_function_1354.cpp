#pragma force_active on
namespace nw4r {
namespace g3d {
class ResMdl {
public:
    void* GetResNode(unsigned long) const;
};
} // namespace g3d
} // namespace nw4r

struct Obj {
    char pad[0xe8];
    void* mdl;
};

extern "C" void fn_80192FF8(void* node, float x, float y, float z);

extern "C" void fn_56_1354(void* unused, const float* pos, Obj* obj, unsigned long idx) {
    void* mdl = 0;
    void* node = 0;
    mdl = obj->mdl;
    if (mdl != 0) {
        node = ((nw4r::g3d::ResMdl*)&mdl)->GetResNode(idx);
        if (node != 0) {
            fn_80192FF8(&node, pos[0], pos[1], pos[2]);
        }
    }
}
