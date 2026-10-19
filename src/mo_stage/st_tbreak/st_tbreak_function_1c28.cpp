#pragma force_active on
struct grMadein {
    ~grMadein();
};

extern "C" grMadein* __dt__8grMadeinFv(grMadein*, int);
extern "C" void __dl__FPv(void*);

extern "C" grMadein* fn_89_1C28(grMadein* object, int shouldDelete) {
    if (object != 0) {
        __dt__8grMadeinFv(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
