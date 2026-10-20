#pragma force_active on
extern "C" void fn_113_68C(void*, short);

extern "C" void* fn_113_630(void* p, short flag) {
    if (p != 0) {
        fn_113_68C(p, 0);
        if (flag > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
