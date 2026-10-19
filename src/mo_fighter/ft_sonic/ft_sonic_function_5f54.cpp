#pragma force_active on
extern "C" void fn_27_5B39C(void*, short);

extern "C" {
void* fn_123_5F54(void* p, short flag) {
    if (p != 0) {
        fn_27_5B39C(p, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
