#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);

extern "C" void* fn_94_2CBC(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_BED74(p1, static_cast<short>(-1));
        if (p2 > 0) {
            operator delete(p1);
        }
    }
    return p1;
}
