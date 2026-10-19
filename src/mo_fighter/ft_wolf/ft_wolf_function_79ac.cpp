#pragma force_active on
extern "C" void* fn_125_42F0(void*, short);

extern "C" void* fn_125_79AC(void* p, short baseDeleting) {
    if (p != 0) {
        fn_125_42F0(p, 0);
        if (baseDeleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
