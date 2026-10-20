#pragma force_active on
struct Src {
    int unk0;
    int unk4;
    unsigned long long v8;
};

extern "C" {
unsigned long long fn_27_8A624(Src *p) {
    return p->v8;
}
}
