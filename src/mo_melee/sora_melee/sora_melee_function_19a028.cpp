#pragma force_active on
struct V { unsigned int a:12; unsigned int b:1; unsigned int c:19; };
extern "C" {
unsigned int fn_27_19A028(const unsigned int *p) {
    union { unsigned int u; V v; } x;
    x.u = p[2];
    return x.v.b;
}
}