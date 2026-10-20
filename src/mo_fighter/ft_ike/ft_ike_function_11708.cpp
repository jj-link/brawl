#pragma force_active on
struct Obj;
extern "C" {
Obj* fn_119_55D0(Obj* p, short flag);

Obj* fn_119_11708(Obj* p, short flag) {
    if (p != 0) {
        fn_119_55D0(p, 0);
        if (flag > 0) {
            delete p;
        }
    }
    return p;
}
}
