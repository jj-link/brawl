#pragma force_active on
struct St {
    unsigned int a;
    unsigned int b;
    unsigned int x : 4;
    unsigned int y : 2;
    unsigned int z : 26;
};

extern "C" void fn_49_6D60(St* p, unsigned int v) {
    p->y = v;
}
