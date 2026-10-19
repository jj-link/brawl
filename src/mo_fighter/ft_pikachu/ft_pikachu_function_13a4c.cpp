#pragma force_active on
extern "C" void* fn_98_13AA8(void*, short);

extern "C" void* fn_98_13A4C(void* accesser, int deleting) {
    if (accesser) {
        fn_98_13AA8(accesser, (short)0);
        if ((short)deleting > 0) operator delete(accesser);
    }
    return accesser;
}
