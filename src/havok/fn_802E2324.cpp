#pragma force_active on
extern "C" char lbl_80487F10[];

struct Value {
    int value;
};

extern "C" void fn_802E1184(void*, Value*);

struct Frame {
    void* p;
    char pad[0x1EC];
} __attribute__((aligned(16)));

extern "C" void* fn_802E2324() {
    Frame f;
    Value value;
    value.value = 0;

    if (&f != 0) {
        Value copy = value;
        fn_802E1184(&f, &copy);
        f.p = lbl_80487F10;
    }

    return f.p;
}
