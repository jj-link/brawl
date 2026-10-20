#pragma force_active on
struct Flags {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int flags;
};

extern "C" unsigned int fn_27_1A22E0(Flags* f) {
    return (f->flags >> 22) & 1;
}
