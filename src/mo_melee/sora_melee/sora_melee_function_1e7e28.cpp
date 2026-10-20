#pragma force_active on
struct Obj {
    int pad[2];
    int flags;
};

extern "C" {
int fn_27_1E7E28(Obj* p) {
    int v = (p->flags << 4) & 0xF8000000;
    return v >> 28;
}
}
