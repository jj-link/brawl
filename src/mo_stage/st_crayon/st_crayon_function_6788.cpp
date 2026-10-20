#pragma force_active on
struct Unk {
    int a;
    int b;
    unsigned int f : 4;
    unsigned int rest : 28;
};

extern "C" void fn_56_6788(Unk* p, unsigned int v) {
    p->f = v;
}
