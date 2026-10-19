#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);

extern "C" void* fn_93_664C(void* object, short deleting) {
    if (object != 0) {
        fn_27_5AE44(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
