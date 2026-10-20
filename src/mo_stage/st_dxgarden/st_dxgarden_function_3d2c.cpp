#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int a : 4;
    signed int b : 4;
};

extern "C" int fn_77_3D2C(Unk* p) {
    return p->b;
}
