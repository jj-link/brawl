#pragma force_active on
extern "C" void fn_27_3544C(void*, short);

extern "C" void* fn_98_4838(void* a, int b) {
    if (a) {
        fn_27_3544C(a, static_cast<short>(-1));
        if (static_cast<short>(b) > 0) operator delete(a);
    }
    return a;
}
