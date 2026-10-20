#pragma force_active on
struct Obj {
    char pad[0x18];
    int f;
};

extern "C" {
char* fn_27_1CA308(Obj* p, int n) {
    int i = (p->f >> 28) + n;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)p + i * 12 + 0x1c;
}
}
