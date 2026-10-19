#pragma force_active on
extern "C" void* fn_27_14B698(void*, short);

extern "C" void* fn_123_6B90(void* p, short flag) {
    if (p != 0) {
        fn_27_14B698(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
