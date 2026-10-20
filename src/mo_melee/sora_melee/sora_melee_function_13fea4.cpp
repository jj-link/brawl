#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Object {
    unsigned char pad[0x114];
    void* target;

    bool hasTarget() const { return target != 0; }
};

extern "C" Vec3 getPos__23soExternalValueAccesserFP11StageObject(void*);
extern "C" const float lbl_27_rodata_10B0;

extern "C" Vec3 fn_27_13FEA4(Object* self) {
    if (self->hasTarget()) {
        return getPos__23soExternalValueAccesserFP11StageObject(self->target);
    }
    return Vec3(lbl_27_rodata_10B0, lbl_27_rodata_10B0, lbl_27_rodata_10B0);
}
