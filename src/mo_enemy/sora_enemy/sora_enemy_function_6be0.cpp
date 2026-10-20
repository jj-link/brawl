#pragma force_active on
extern "C" void fn_41_58A4(const void*, const void*, float*);
extern "C" double atan2(double, double);
extern "C" void* __memcpy(void*, const void*, unsigned long);

extern const float lbl_41_rodata_48;

struct Vec2 {
    float x, y;
};

extern "C" float fn_41_6BE0(const void* a, const void* b) {
    Vec2 v[3];
    fn_41_58A4(b, a, &v[0].x);
    __memcpy(&v[1], &v[0], sizeof(Vec2));
    __memcpy(&v[2], &v[1], sizeof(Vec2));
    float x = v[2].x;
    float y = v[2].y;
    return lbl_41_rodata_48 * (float)atan2(y, x);
}
