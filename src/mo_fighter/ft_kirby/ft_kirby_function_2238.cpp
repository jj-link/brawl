#pragma force_active on
extern "C" {
void fn_96_20C0(void*, signed short);
}

extern "C" void* fn_96_2238(void* p, signed short flag) {
    if (p != 0) {
        fn_96_20C0(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
