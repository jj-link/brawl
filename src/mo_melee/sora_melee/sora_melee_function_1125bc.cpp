#pragma force_active on
struct S {
    unsigned char pad[0x490];
    float f;
};

extern "C" void fn_27_1125BC(float val, S** p) {
    (*p)->f = val;
}
