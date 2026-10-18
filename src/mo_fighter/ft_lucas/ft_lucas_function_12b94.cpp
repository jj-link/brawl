#pragma force_active on
struct Vec3f {
    float v[3];

    void set(float a, float b, float c) {
        v[0] = a;
        v[1] = b;
        v[2] = c;
    }
};

extern "C" {
void fn_114_12B94(Vec3f* p, float a, float b, float c) {
    p->set(a, b, c);
}
}