#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct LargeObject {
    char pad[0x1dc];
    Vec3f v;
};

extern "C" void fn_67_91A0(LargeObject *obj, float x, float y, float z) {
    obj->v.x = x;
    obj->v.y = y;
    obj->v.z = z;
}
