#pragma force_active on
struct Unknown {
    int a;
    int b;
    int c;
};

extern "C" void fn_1_36738(Unknown *p) {
    p->c = 2;
}
