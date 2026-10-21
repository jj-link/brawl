#pragma force_active on
struct S {
    unsigned char pad[0xC];
    float f;
};

extern "C" float fn_8004E94C(S** p) {
    return (*p)->f;
}
