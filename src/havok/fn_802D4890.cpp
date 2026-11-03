#pragma force_active on

extern "C" char lbl_80487588[];

struct Result {
    void* value;
    char pad[8];
    void* secondary;
    char rest[0x40];
};

extern "C" void fn_802D5284(Result*, int*);

extern "C" void* fn_802D4890() {
    Result out __attribute__((aligned(16)));
    int zero = 0;
    if (&out != 0) {
        int in = zero;
        fn_802D5284(&out, &in);
        out.value = lbl_80487588;
        out.secondary = lbl_80487588 + 0x28;
    }
    return out.value;
}
