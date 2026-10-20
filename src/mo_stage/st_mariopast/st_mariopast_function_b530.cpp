#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int pad1 : 27;
    unsigned int flag : 1;
    unsigned int rest : 4;
};

extern "C" unsigned int fn_48_B530(Unk* p) {
    return p->flag;
}
