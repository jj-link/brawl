#pragma force_active on
extern "C" void* fn_99_1D80(void* object, short deleting);

extern "C" void* fn_99_1D24(void* object, short deleting) {
    if (object) {
        fn_99_1D80(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
