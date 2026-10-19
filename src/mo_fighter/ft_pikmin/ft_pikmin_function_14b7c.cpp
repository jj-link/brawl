#pragma force_active on
extern "C" void* fn_27_C21DC(void*, short);

extern "C" void* fn_113_14B7C(void* object, short deleting) {
    if (object != 0) {
        fn_27_C21DC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
