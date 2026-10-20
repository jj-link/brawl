#pragma force_active on
struct S {
    int a;
    int b;
    int c;
};

extern "C" int fn_73_9F40(S* s) {
    return s->c >> 29;
}
