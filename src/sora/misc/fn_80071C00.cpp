#pragma force_active on
struct Sub { int b, c, d; };
struct S {
    int a;
    Sub sub;
    S(Sub t) : a(0), sub(t) {}
};

extern "C" S fn_80071C00(S* s) {
    return S(s->sub);
}
