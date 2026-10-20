#pragma force_active on
typedef signed short s16;

extern "C" void fn_93_1BB4(void* p, s16 arg);

extern "C" void* fn_93_1C18(void* p, s16 flag) {
    if (p != 0) {
        fn_93_1BB4(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
