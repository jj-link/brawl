#pragma force_active on
struct Src {
    float a;
    char pad0[0x14 - 0x4];
    float b;
    char pad1[0x28 - 0x18];
    float c;
};

struct Dst {
    char pad[0xd0];
    float a;
    float b;
    float c;
};

extern "C" {
void fn_802E4A04(Dst* dst, const Src* src) {
    float a;
    float b;
    float c;
    c = src->c;
    b = src->b;
    a = src->a;
    dst->b = b;
    dst->a = a;
    dst->c = c;
}
}
