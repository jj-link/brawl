#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int flags;
};

extern "C" {
int fn_40_1E3B8(Obj* obj) {
    unsigned int x = obj->flags;
    unsigned int r = (x << 12) | (x >> 20);
    return ((int)(r & 0xFE000000u)) >> 26;
}
}
