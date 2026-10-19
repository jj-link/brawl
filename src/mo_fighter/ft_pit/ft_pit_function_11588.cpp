#pragma force_active on
struct S {
    char pad[8];
    void* a;
    void* b;
    void* c;
};

extern "C" void fn_112_11588(S* s, void* v) {
    s->c = v;
    s->b = v;
    s->a = v;
}
