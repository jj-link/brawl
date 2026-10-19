#pragma force_active on
extern "C" void fn_67_23C8(void* p, int flag);

extern "C" void* fn_67_8DD0(void* p, int size) {
    if (p) {
        fn_67_23C8(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
