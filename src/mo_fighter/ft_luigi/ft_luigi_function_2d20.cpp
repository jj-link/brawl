#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);

extern "C" void* fn_99_2D20(void* object, short deleting) {
    if (object) {
        fn_27_19816C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
