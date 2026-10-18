#pragma force_active on
extern "C" void* fn_100_3858(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_ADFC(void* ptr, short count) {
    if (ptr == 0) {
        goto done;
    }

    if (ptr != 0) {
        fn_100_3858(ptr, 0);
    }

    if (count <= 0) {
        goto done;
    }

    __dl__FPv(ptr);

done:
    return ptr;
}
