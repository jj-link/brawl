#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

struct S {
    int a;
    int b;
    void* m;
};

extern "C" void fn_27_224B90(void*);
extern "C" void fn_27_224CC0(void*, const Color*, unsigned char, unsigned char);
extern "C" void fn_27_224C28(void*);

extern "C" void fn_27_23A074(S* s, int mode, Color* c) {
    unsigned char a, b, g, r;

    switch (mode) {
    case 0:
        fn_27_224B90(s->m);
        c->a = 0;
    case 1: {
        r = c->r;
        g = c->g;
        b = c->b;
        a = c->a;
        Color t;
        t.r = r;
        t.g = g;
        t.b = b;
        t.a = a;
        fn_27_224CC0(s->m, &t, g, r);
        break;
    }
    case 2:
        fn_27_224C28(s->m);
        break;
    }
}