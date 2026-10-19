#pragma force_active on
extern "C" void* fn_27_19874C(void*, short);

extern "C" void* fn_121_6508(void* p, short flag) {
    if (p != 0) {
        fn_27_19874C(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
