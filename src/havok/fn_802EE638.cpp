#pragma force_active on

struct Src {
    float a, b, c, d;
};

struct Dst {
    char pad[0x10];
    float a, b, c, d;
};

extern "C" void fn_802EE638(Dst* dst, const Src* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
}
