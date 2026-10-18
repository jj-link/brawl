#pragma force_active on
struct Unk {
    char pad[4];
    int f4;
    short f8;
    short fA;
};

extern "C" void fn_27_EF174(Unk* p) {
    p->f4 = -1;
    p->f8 = 0;
    p->fA = -1;
}
