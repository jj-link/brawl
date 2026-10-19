#pragma force_active on
extern "C" void* fn_27_69684(void*, short);

extern "C" void* fn_99_53D8(void* object, short deleting) {
    if (object) {
        fn_27_69684(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
