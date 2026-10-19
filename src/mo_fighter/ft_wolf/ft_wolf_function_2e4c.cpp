#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
void operator delete(void*);

extern "C" void* fn_125_2E4C(void* p, short flag) {
    if (p != 0) {
        fn_27_19816C(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
