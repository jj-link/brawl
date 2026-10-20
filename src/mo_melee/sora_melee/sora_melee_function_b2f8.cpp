#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}
};

struct ResNode {
    char pad[0x2c];
    Vec3 rotation;
};

struct ResMdl {
    void* data;
};

struct ModelData {
    char pad[0xe8];
    void* mdl;
};

struct ModelModule {
    char pad[0xc];
    ModelData* data;
};

extern "C" ResNode* GetResNode__Q34nw4r3g3d6ResMdlCFi(const ResMdl*, int);

extern "C" Vec3 getResFileNodeRotation__17soModelModuleImplFUl(
    ModelModule* self, unsigned long index)
{
    ResMdl mdl = {self->data->mdl};
    ResNode* node = GetResNode__Q34nw4r3g3d6ResMdlCFi(&mdl, index);
    return node->rotation;
}
