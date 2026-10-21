#pragma force_active on
extern "C" int fn_800B5854(void*, int, int, int, int);

struct S {
    char pad[0x74];
    void* objs[3];
    char pad2[0x450 - 0x80];
    bool flags[3];
};

extern "C" void fn_16_4BD8(S* arg0, int arg1) {
    int f[3];
    int* q = f;
    bool* b = arg0->flags;
    *q++ = !*b++;
    *q++ = !*b++;
    *q++ = !*b++;
    for (int i = 0; i < 3; i++) {
        fn_800B5854(arg0->objs[i], i == arg1 ? 2 : f[i], 0x11, 1, 0);
    }
}
