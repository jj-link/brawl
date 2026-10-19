#pragma force_active on
extern "C" void* fn_95_3864(void*, short);

extern "C" void* fn_95_DB48(void* p, short flag) {
    if (p != 0) {
        fn_95_3864(p, 0);
        if (flag > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
