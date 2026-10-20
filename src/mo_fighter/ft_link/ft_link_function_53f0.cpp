#pragma force_active on
extern "C" void* fn_27_1A3530(void*, short);

extern "C" void* fn_93_53F0(void* p, short flag) {
    if (p != 0) {
        fn_27_1A3530(p, (short)-1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
