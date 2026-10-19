#pragma force_active on
struct Obj {
    int x;
};

extern "C" Obj* fn_27_174314(Obj* p, int n) {
    if (p && n > 0) {
        delete p;
    }
    return p;
}
