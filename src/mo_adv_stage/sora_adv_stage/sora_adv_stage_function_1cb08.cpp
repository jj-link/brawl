#pragma force_active on
struct Triple {
    int a;
    int b;
    int c;
};

extern "C" {
void fn_40_1CB08(Triple* t) {
    t->a = 0;
    t->b = 0;
    t->c = 0;
}
}
