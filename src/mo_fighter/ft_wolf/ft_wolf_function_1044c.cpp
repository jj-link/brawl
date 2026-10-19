#pragma force_active on
extern "C" void* fn_125_42F0(void* p, short size);

extern "C" void* fn_125_1044C(void* p, short size) {
    if (p != 0) {
        fn_125_42F0(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
