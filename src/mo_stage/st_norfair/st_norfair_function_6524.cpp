#pragma force_active on

struct S {
    char pad[8];
    unsigned int flags;
};

extern "C" int fn_54_6524(S *s) {
    return (int)((s->flags << 2) & 0xE0000000) >> 30;
}
