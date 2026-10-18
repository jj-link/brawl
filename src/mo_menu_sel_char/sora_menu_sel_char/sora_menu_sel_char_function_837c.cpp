#pragma force_active on
struct S {
    char a[0x14];
    int b;
};

extern "C" int fn_10_837C(S* ptr) {
    return (ptr->b >> 8) & 1;
}
