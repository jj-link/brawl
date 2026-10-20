#pragma force_active on
struct FloatPair {
    char pad[8];
    float a;
    float b;
};

extern "C" {
float fn_41_33CE0(FloatPair* p) {
    return p->a * p->b;
}
}
