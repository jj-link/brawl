#pragma force_active on
struct S {
    unsigned char pad[0x28];
    float f;
};

extern "C" float fn_27_1118D8(S** p) {
    return (*p)->f;
}
