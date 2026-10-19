#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);

extern "C" void* fn_99_5B10(void* object, short deleting) {
    if (object) {
        fn_27_1A75E4(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
