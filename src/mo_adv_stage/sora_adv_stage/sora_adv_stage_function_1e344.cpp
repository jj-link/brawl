#pragma force_active on
struct Flags {
    int pad[2];
    unsigned int hi : 6;
    unsigned int rest : 26;
};

extern "C" void fn_40_1E344(Flags* p, unsigned int v) {
    p->hi = v;
}
