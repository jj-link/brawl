#pragma force_active on
void operator delete(void* p);

struct Obj {
    ~Obj() {}
};

extern "C" {
Obj* fn_119_55D0(Obj* p, short flag) {
    if (p) {
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
