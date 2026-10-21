#pragma force_active on

struct RawVec3 {
    float x, y, z;
};

struct Vec3 {
    float x, y, z;

    Vec3() {}

    void set(const RawVec3& v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
};

struct Object {
    void* unused;
    void* pane;
};

extern "C" {
extern char lbl_10_data_CEC[];
extern const float lbl_10_rodata_880;

void fn_800B6E84(RawVec3*, void*);
void fn_800B6D68(RawVec3*, void*, const char*);

float fn_10_1BDD0(Object* self) {
    Vec3 a;
    RawVec3 rawA;
    RawVec3 rawB;
    Vec3 b;

    fn_800B6E84(&rawA, self->pane);
    a.set(rawA);
    fn_800B6D68(&rawB, self->pane, lbl_10_data_CEC);
    b.set(rawB);

    float r = lbl_10_rodata_880 * b.x;
    return a.x * r;
}
}
