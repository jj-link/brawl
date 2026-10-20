#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" int fn_27_CA6D0(Obj* p) {
    return (int)((p->flags >> 21) & 0x3F) << 26 >> 27;
}
