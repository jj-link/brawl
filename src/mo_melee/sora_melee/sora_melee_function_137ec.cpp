#pragma force_active on
extern "C" void* fn_27_1F9CC(void*, short);

extern "C" void* fn_27_137EC(void* p, int flag) {
    if (p != 0) {
        fn_27_1F9CC(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
