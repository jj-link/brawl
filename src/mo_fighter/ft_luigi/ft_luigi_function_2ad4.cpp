#pragma force_active on
extern "C" void* fn_27_14CD30(void*, short);

extern "C" void* fn_99_2AD4(void* object, short deleting) {
    if (object) {
        fn_27_14CD30(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
