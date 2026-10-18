#pragma force_active on
struct Obj {
    int dummy;
};

extern "C" Obj* fn_110_40EC(Obj* p, short n) {
    if (p && n > 0) {
        delete p;
    }
    return p;
}
