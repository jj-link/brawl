#pragma force_active on
extern "C" void* fn_93_7100(void*, short);

extern "C" void* fn_93_D72C(void* p, short flag) {
    if (p != 0) {
        fn_93_7100(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
