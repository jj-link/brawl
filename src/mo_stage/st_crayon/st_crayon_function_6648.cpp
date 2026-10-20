#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int b0 : 6;
    unsigned int flag : 1;
    unsigned int rest : 25;
};

extern "C" void fn_56_6648(Unk* p) {
    p->flag = 0;
}
