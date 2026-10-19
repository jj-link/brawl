#pragma force_active on
extern "C" void fn_41_FB10(void*, short);

extern "C" void* fn_41_FB50(void* p, short n) {
    if (p != 0) {
        fn_41_FB10(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
