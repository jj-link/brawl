#pragma force_active on
extern "C" void* fn_27_1A09B4(void*, short);

extern "C" void* fn_99_2284(void* object, short deleting) {
    if (object) {
        fn_27_1A09B4(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
