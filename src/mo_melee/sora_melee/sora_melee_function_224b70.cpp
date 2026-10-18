#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_33D8;

class Stage {
public:
    void getBamperVector(Vec3f* v);
};

void Stage::getBamperVector(Vec3f* v) {
    if (v == 0) {
        return;
    }
    float zero = lbl_27_rodata_33D8;
    v->x = zero;
    v->y = zero;
    v->z = zero;
}
