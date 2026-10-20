#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct KirifudaData {
    char pad[0xB8];
    float a;
    float b;
    float c;
    float d;
};

extern float lbl_27_rodata_33D0;

class Stage {
public:
    void getKirifudaScale(Vec3f* out, unsigned long kind);
    char pad[0x98];
    KirifudaData* kd;
};

void Stage::getKirifudaScale(Vec3f* out, unsigned long kind) {
    float zero = lbl_27_rodata_33D0;
    out->x = zero;
    out->y = zero;
    out->z = zero;
    if (this->kd == 0) {
        return;
    }
    if (kind >= 7) {
        return;
    }
    switch (kind) {
    case 5:
        out->x = this->kd->a;
        out->y = this->kd->b;
        return;
    case 6:
        out->x = this->kd->c;
        out->y = this->kd->d;
        return;
    default:
        return;
    }
}
