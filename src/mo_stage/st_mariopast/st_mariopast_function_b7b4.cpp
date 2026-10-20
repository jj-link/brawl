#pragma force_active on
struct X {
    int f0;
    int f4;
    int f8;
};

extern "C" int fn_48_B7B4(struct X *a) {
    return a->f8 >> 25;
}
