#pragma force_active on
struct Result {
    int value;
    char rest[60];
};
extern "C" void fn_802DA52C(Result*, int*);
extern "C" int fn_802DA4E4() {
    __attribute__((aligned(16))) Result out;
    int zero = 0;
    if (&out != 0) {
        int in = zero;
        fn_802DA52C(&out, &in);
    }
    return out.value;
}
