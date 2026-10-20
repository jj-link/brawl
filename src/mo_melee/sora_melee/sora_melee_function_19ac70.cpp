#pragma force_active on
struct S {
    char pad[8];
    unsigned int v;
};

extern "C" int fn_27_19AC70(S* p) {
    return (p->v >> 25) & 1;
}
