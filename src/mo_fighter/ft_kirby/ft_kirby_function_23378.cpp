#pragma force_active on
extern "C" void* fn_96_233D4(void* p, short size);

extern "C" void* fn_96_23378(void* p, short size) {
    if (p != 0) {
        fn_96_233D4(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
