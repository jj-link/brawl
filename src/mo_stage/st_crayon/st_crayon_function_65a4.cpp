#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int a : 4;
    signed int b : 2;
    unsigned int c : 26;
};

extern "C" int fn_56_65A4(Unk* p) {
    return p->b;
}
