#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_62B8(void* object, int deleting) {
    if (object == 0) {
        goto done;
    }
    if (object != 0) {
        fn_27_1A15B8(object, static_cast<short>(-1));
    }
    if (static_cast<short>(deleting) <= 0) {
        goto done;
    }
    __dl__FPv(object);

done:
    return object;
}
