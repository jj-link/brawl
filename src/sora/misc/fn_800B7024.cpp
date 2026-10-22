#pragma force_active on
namespace nw4r { namespace g3d {
class ResMdl {
public:
    void* GetResNode(const char* name) const;
    void* m_ptr;
};
}}

struct Vec3f { float x,y,z; };
struct ModelData { char pad[0xe8]; nw4r::g3d::ResMdl mdl; };
struct ModelModule { char pad[0x10]; ModelData* data; };

extern "C" void fn_800B7024(ModelModule* self, Vec3f* out, const char* name) {
    ModelData* d = self->data;
    float* node = (float*)nw4r::g3d::ResMdl(d->mdl).GetResNode(name);
    out->x = node[11];
    out->y = node[12];
    out->z = node[13];
}
