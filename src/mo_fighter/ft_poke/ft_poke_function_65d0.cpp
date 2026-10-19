#pragma force_active on
extern "C" void fn_27_69684(void*, short);

extern "C" void* fn_116_65D0(void* p, short flag) {
    if (p != 0) {
        fn_27_69684(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
