#pragma force_active on
extern "C" void* fn_109_39C8(void*, short);

extern "C" void* fn_109_A5D8(void* p, short baseDeleting) {
    if (p != 0) {
        fn_109_39C8(p, 0);
        if (baseDeleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
