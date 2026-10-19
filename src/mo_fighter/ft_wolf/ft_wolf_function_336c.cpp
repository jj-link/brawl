#pragma force_active on
extern "C" void* fn_125_33C8(void* object, short deleting);

extern "C" void* fn_125_336C(void* p, short deleting) {
    if (p != 0) {
        fn_125_33C8(p, 0);
        if (deleting > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
