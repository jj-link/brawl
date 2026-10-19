#pragma force_active on
struct Obj {
    char pad[0x18];
    float a;
    float b;
    float c;
    float d;
};

extern "C" {
void fn_41_2797C(Obj* dst, const float* src) {
    dst->a = src[0];
    dst->b = src[1];
    dst->c = src[2];
    dst->d = src[3];
}
}
