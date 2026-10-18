#pragma force_active on
struct Target {
    char pad[0x4E8];
    float x;
    float y;
    float z;
};

extern "C" void fn_27_111B9C(Target** pp, const float* src) {
    Target* t = *pp;
    t->x = src[0];
    t->y = src[1];
    t->z = src[2];
}
