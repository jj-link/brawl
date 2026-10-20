#pragma force_active on
struct S {
    unsigned char pad[0x4a4];
    float f;
};

extern "C" {
void fn_27_111DA4(S** p, float val) {
    (*p)->f = val;
}
}
