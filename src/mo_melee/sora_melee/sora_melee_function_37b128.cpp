#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37B128(void* p, int flag) {
    if (p != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(p) + 0x178, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
