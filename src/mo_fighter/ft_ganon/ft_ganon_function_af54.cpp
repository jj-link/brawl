#pragma force_active on
extern "C" void* fn_109_39C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_AF54(void* p, short baseDeleting) {
    if (p != 0) {
        fn_109_39C8(p, 0);
        if (baseDeleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
