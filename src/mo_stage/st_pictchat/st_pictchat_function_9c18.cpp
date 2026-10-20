#pragma force_active on
struct S {
    char pad[0x7f0];
    int a;
    int pad2;
    int b;
};

extern "C" void fn_73_9C18(S* s, int a, int b) {
    s->a = a;
    s->b = b;
}
