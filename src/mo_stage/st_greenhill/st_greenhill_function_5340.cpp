#pragma force_active on
struct Fn72Obj {
    char pad[8];
    int flags;
};

extern "C" void* fn_72_5340(Fn72Obj* self, int index) {
    int n = (self->flags >> 28) + index;
    if (n >= 7) {
        n -= 7;
    }
    return (char*)self + (n << 3) + 12;
}
