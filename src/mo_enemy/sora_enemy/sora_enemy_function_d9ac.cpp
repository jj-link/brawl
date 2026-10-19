#pragma force_active on
typedef signed short s16;

extern "C" void fn_41_DAEC(void* p);

extern "C" void* fn_41_D9AC(void* p, s16 flag) {
    if (p != 0) {
        fn_41_DAEC(p);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
