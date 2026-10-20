#pragma force_active on
typedef int s32;

struct X {
    unsigned char pad[8];
    s32 value;
};

extern "C" void *fn_27_D93B8(X *p, s32 index) {
    s32 n = (p->value >> 25) + index;
    if (n >= 33)
        n -= 33;
    return (char *)p + n * 48 + 12;
}
