#pragma force_active on

extern "C" void* fn_112_451C(void* p, short flags);

extern "C" void* fn_112_117EC(void* p, short deleting) {
    if (p != 0) {
        fn_112_451C(p, 0);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
