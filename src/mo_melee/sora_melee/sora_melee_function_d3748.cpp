#pragma force_active on
struct FieldWord {
    unsigned int hi : 5;
    unsigned int mid : 5;
    unsigned int lo : 22;
};

extern "C" void fn_27_D3748(char *base, unsigned int v) {
    FieldWord *p = (FieldWord *)(base + 8);
    p->mid = v;
}
