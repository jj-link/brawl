#pragma force_active on

struct Foo {
    int _0;
    int _4;
};

extern "C" void fn_801D7718(Foo*, int);
extern "C" void fn_801D7774(Foo*, int);

extern "C" void fn_80192A2C(Foo** pp, int cond) {
    Foo* f = *pp;
    int v = f->_4;
    if (cond != 0) {
        fn_801D7718(f, v);
    } else {
        fn_801D7774(f, v);
    }
}
