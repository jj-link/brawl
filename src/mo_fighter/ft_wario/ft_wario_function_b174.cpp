#pragma force_active on
extern "C" void fn_110_AFDC(void*, short);

extern "C" void* fn_110_B174(void* p, short deleting) {
    if (p != 0) {
        fn_110_AFDC(p, 0);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
