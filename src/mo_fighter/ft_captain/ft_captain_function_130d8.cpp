#pragma force_active on
struct Flags {
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char rest : 6;
};

extern "C" bool fn_100_130D8(unsigned char* p) {
    Flags* f = reinterpret_cast<Flags*>(p + 0xA4);
    return f->f1;
}
