#pragma force_active on
extern "C" {
void* fn_27_14B698(void*, short);
}

extern "C" void* fn_125_7D88(void* p, short flag) {
    if (p != 0) {
        fn_27_14B698(p, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
