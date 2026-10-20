#pragma force_active on
struct RawVec3 {
    float x, y, z;
};

struct Vec3 {
    float x, y, z;

    Vec3(const RawVec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Object {
    void* unused;
    void* pane;
};

extern "C" {
extern char lbl_10_data_CEC[];
extern const float lbl_10_rodata_880;

RawVec3 fn_800B6D68(void*, const char*);

float fn_10_1BD7C(Object* self) {
    Vec3 v(fn_800B6D68(self->pane, lbl_10_data_CEC));
    return lbl_10_rodata_880 * v.x;
}
}
