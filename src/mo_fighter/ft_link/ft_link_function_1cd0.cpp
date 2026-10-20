#pragma force_active on
extern "C" void fn_93_1BB4(void* p1, short p2);

extern "C" void* fn_93_1CD0(void* p1, short p2) {
    if (p1 != 0) {
        fn_93_1BB4(p1, 0);
        if (p2 > 0) {
            operator delete(p1);
        }
    }
    return p1;
}
