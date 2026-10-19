#pragma force_active on
extern "C" void fn_27_3544C(void*, short);

extern "C" void* fn_126_4868(void* p, short flag) {
    if (p != 0) {
        fn_27_3544C(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
