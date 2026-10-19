#pragma force_active on
extern "C" void* fn_95_F6F4(void* p, short flag);

extern "C" void* fn_95_F698(void* p, short flag) {
    if (p != 0) {
        fn_95_F6F4(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
