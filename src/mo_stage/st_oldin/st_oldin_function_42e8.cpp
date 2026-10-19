#pragma force_active on
struct S {
    char pad[0x6c];
    unsigned char b;
};

extern "C" int fn_53_42E8(S* s) {
    return (s->b >> 3) & 1;
}
