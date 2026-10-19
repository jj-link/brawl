#pragma force_active on
extern "C" void* fn_27_1A405C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_104D8(void* ptr, short deleting) {
    if (ptr != 0) {
        fn_27_1A405C(ptr, -1);
        if (deleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
