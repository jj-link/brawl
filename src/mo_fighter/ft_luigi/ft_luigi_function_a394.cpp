#pragma force_active on
extern "C" void* fn_99_A1FC(void*, short);

extern "C" void* fn_99_A394(void* object, short deleting) {
    if (object) {
        fn_99_A1FC(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
