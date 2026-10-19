#pragma force_active on
extern "C" void fn_27_1362C(void*, short);

extern "C" void* fn_116_1F20(void* p, short flag) {
    if (p != 0) {
        fn_27_1362C(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
