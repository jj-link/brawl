#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct fn27Obj {
    Vec3f a;
    float f;
    char pad[0x34 - 0x10];
    Vec3f b;
};

extern "C" void fn_27_2B38(fn27Obj* obj, const Vec3f* src1, const Vec3f* src2, float f) {
    obj->a.x = src1->x;
    obj->a.y = src1->y;
    obj->a.z = src1->z;
    obj->f = f;
    obj->b.x = src2->x;
    obj->b.y = src2->y;
    obj->b.z = src2->z;
}
