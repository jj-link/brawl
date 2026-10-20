#pragma force_active on
struct Unk {
    char pad[8];
    unsigned int a : 2;
    int b : 2;
    unsigned int c : 28;
};

extern "C" int fn_56_6608(Unk* p) {
    return p->b;
}
