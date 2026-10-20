#pragma force_active on
struct Obj {
    unsigned char pad[0x18];
    int f18;
};

extern "C" {
void* fn_27_1BB580(Obj* p, int idx) {
    int i = (p->f18 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (unsigned char*)p + i * 12 + 0x1c;
}
}
