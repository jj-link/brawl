#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);

extern "C" void* fn_121_2F2C(void* p, short flag) {
    if (p != 0) {
        fn_27_1A75E4(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
