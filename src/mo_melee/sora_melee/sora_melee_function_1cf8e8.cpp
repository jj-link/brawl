#pragma force_active on
struct S {
    int x;
    int y;
    int z;
};

extern "C" int fn_27_1CF8E8(S *s) {
    return s->z >> 26;
}
