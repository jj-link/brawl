#pragma force_active on
struct Self {
    char pad[0xcc];
    unsigned mask;
};

extern "C" void fn_801ABA14(void*, int, int, void*);

extern "C" void fn_801AB9D8(Self* self, unsigned int a, int b, void* c) {
    int result;
    if (a < 9 && ((1 << (a - 1)) & self->mask)) {
        result = 1;
    } else {
        result = 0;
    }
    if (result != 0) {
        return;
    }
    fn_801ABA14(self, a, b, c);
}
