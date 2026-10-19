#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);

extern "C" void* fn_99_5C24(void* object, short deleting) {
    if (object) {
        fn_27_C9EDC(object, (short)-1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
