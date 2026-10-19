#pragma force_active on
struct grMadein;

extern "C" void __dt__8grMadeinFv(grMadein*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
grMadein* fn_53_4258(grMadein* object, int flags) {
    if (object) {
        __dt__8grMadeinFv(object, 0);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
