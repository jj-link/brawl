#pragma force_active on
struct Holder {
    char pad[8];
    int flag;
};

extern "C" void* fn_27_1B014C(Holder* self, int idx) {
    int s = self->flag;
    s = s >> 28;
    int n = s + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + n * 0xB8 + 0xC;
}
