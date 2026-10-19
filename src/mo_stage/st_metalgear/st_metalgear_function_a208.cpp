#pragma force_active on
struct Holder {
    int a;
    int b;
    int flags;
};

extern "C" void* fn_71_A208(Holder* self, int index) {
    int shift = self->flags >> 28;
    int n = shift + index;
    if (n >= 6) {
        n -= 6;
    }
    return (char*)self + n * 8 + 0xc;
}
