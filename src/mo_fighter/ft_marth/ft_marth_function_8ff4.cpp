#pragma force_active on
extern "C" void fn_106_815C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_8FF4(void* ptr, short count) {
    if (ptr == 0) {
        goto done;
    }

    if (ptr != 0) {
        fn_106_815C(ptr, 0);
    }

    if (count > 0) {
        __dl__FPv(ptr);
    }

done:
    return ptr;
}
