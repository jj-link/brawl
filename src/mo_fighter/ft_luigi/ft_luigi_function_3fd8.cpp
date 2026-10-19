#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);

extern "C" void* fn_99_3FD8(void* object, short deleting) {
    if (object) {
        fn_27_A1E80(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
