#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);

extern "C" void* fn_99_3034(void* object, short deleting) {
    if (object) {
        fn_27_A0C34(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
