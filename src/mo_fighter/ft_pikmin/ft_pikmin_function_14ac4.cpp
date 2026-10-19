#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C31CC(void*, short);

extern "C" void* fn_113_14AC4(void* object, short deleting) {
    if (object != 0) {
        fn_27_C31CC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
