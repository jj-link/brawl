#pragma force_active on

struct Result {
    int value;
    char rest[0x4C];
};

extern "C" void fn_802D5284(Result*, int*);

extern "C" int fn_802D523C() {
    __attribute__((aligned(16))) Result out;
    int zero = 0;
    if (&out != 0) {
        int in = zero;
        fn_802D5284(&out, &in);
    }
    return out.value;
}
