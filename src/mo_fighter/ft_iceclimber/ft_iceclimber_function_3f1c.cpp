#pragma force_active on
extern "C" void* fn_27_64930(void*, short);

extern "C" void* fn_105_3F1C(void* p, short flag) {
    if (p != 0) {
        fn_27_64930(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
