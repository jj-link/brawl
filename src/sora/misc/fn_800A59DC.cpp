#pragma force_active on
struct Obj {
    char pad[0x18];
    float a;
};

extern "C" {
void fn_800A59DC(Obj* dst, const float* src) {
    dst->a = src[0];
}
}
