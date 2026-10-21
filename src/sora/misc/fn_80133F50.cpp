#pragma force_active on

struct S {
    int pad[2];
    unsigned f : 8;
    unsigned rest : 24;
};

extern "C" void fn_80133F50(S* s) {
    s->f = 3;
}
