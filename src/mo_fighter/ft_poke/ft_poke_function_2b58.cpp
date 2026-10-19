#pragma force_active on
extern "C" {
void* fn_27_14CD30(void*, short);
}

extern "C" void* fn_116_2B58(void* p, short flag) {
    if (p != 0) {
        fn_27_14CD30(p, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
