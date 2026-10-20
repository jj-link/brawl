#pragma force_active on
extern const float lbl_27_rodata_4398;

union Vec3 {
    struct { float x, y, z; };
    float values[3];

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct GimmickData {
    char padding[0x20];
    Vec3 scale;
};

struct grGimmick {
    char padding[0xD4];
    GimmickData* data;
};

extern "C" Vec3 getScale__9grGimmickFv(grGimmick* self) {
    if (self->data)
        return self->data->scale;

    return Vec3(lbl_27_rodata_4398, lbl_27_rodata_4398, lbl_27_rodata_4398);
}
