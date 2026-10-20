#pragma force_active on
namespace nw4r { namespace g3d {
struct ResNode;
class ResMdl {
public:
    ResMdl(void* p) : m_ptr(p) {}
    ResNode* GetResNode(int idx) const;
    void* m_ptr;
};
}}

struct Vec3f {
    float x;
    float y;
    float z;
    Vec3f() {}
    Vec3f(float a, float b, float c) : x(a), y(b), z(c) {}
};

class soModelModuleImpl {
public:
    Vec3f getResFileNodeTranslate(unsigned long index);
};

Vec3f soModelModuleImpl::getResFileNodeTranslate(unsigned long index) {
    char* obj = *(char**)((char*)this + 0xc);
    void* data = *(void**)(obj + 0xe8);
    nw4r::g3d::ResMdl mdl(data);
    char* node = (char*)mdl.GetResNode(index);
    Vec3f v;
    v.x = *(float*)(node + 0x38);
    v.y = *(float*)(node + 0x3c);
    v.z = *(float*)(node + 0x40);
    return v;
}
