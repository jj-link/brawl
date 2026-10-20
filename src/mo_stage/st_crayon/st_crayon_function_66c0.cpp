#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int field : 4;
    unsigned int rest : 28;
};

extern "C" void fn_56_66C0(Unk* p, int v) {
    p->field = v;
}
